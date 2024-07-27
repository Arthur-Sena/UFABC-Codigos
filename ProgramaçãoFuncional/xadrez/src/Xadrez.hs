module Xadrez
    ( -- Inicializadores
      jogoInicial,
      tabuleiroInicial,
      -- Auxiliares
      trocaTurno,
      outraCor,
      resetEnPassant,
      setEnPassant,
      dentroTab,
      -- Coordenadas
      coordRei,
      coordTime,
      coordPecaTime,
      -- Verificação de Casa
      verificaCasa,
      -- Verificação de Movimentos
      validaMovClasse,
      validaMov,
      capturaPeaoErro,
      capturaProprio,
      pecaNoCaminho,
      podeMover,
      -- Funções de Movimentações
      movSemChecar,
      movePeca,
      removePeca,
      colocaPeca,
      alteraCasa,
      -- Roque
      removeRoque,
      casoRoque,
      roqueValido,
      roquePermitido,
      roque,
      -- Funções Utilizadas no Jogo
      -- Promote
      fazPromote,
      promote,
      existePromote,
      -- Condições de Jogo
      check,
      reiAfogado,
      existeMovValido,
      checkMate,
      -- Realização de Movimento
      move,
      jogada,
      -- Imprime jogo.
      printTab,
      printCasas,
      printCasaComCor
    ) where

import Elementos
import Data.Maybe
import Data.Either
import Data.List
import Data.Char
import System.Console.ANSI
-- Código realizado utilizando o código da biblioteca "chesshs-0.2.1" como auxílio.

---
---- Inicializadores
---


-- Gera uma config. inicial de um tabuleiro de xadrez.
jogoInicial :: Jogo
jogoInicial = Jogo Branco "QKqk" Nothing tabuleiroInicial

-- Gera um tabuleiro com as peças nas posições iniciais.
tabuleiroInicial :: Tabuleiro
tabuleiroInicial = [linhaRP, linhaFP] ++ vazio ++ [linhaFB, linhaRB]
  where
    linhaRP        = [(Casa (0,y) (retaguarda Preto !! y)) | y <- [0,1..7]]
    linhaFP        = [(Casa (1,y) (frente Preto) )| y <- [0,1..7]]
    vazio          = [[(Casa (x,y) Nothing) | y <- [0,1..7]] | x <- [2,3..5]]
    linhaFB        = [(Casa (6,y) (frente Branco) )| y <- [0,1..7]]
    linhaRB        = [(Casa (7,y) (retaguarda Branco !! y)) | y <- [0,1..7]]
    retaguarda cor = map Just $ map (Peca $ cor) [Torre, Cavalo, Bispo, Rainha, Rei, Bispo, Cavalo, Torre]
    frente cor     = Just $ Peca cor Peao


---
---- Auxiliares.
---


-- Troca o turno de um jogo.
trocaTurno :: Jogo -> Jogo
trocaTurno jogo = jogo { turno = outraCor $ turno jogo }

-- Dada uma cor devolve a outra. (Para resgatar o time oposto)
outraCor :: Cor -> Cor
outraCor x
  | x == Branco = Preto
  | otherwise   = Branco

-- Troca EnPassant para marcar como inválido.
resetEnPassant :: Jogo -> Jogo
resetEnPassant jogo = jogo { enpassant = Nothing }

-- Troca EnPassant para indicar a casa onde este mov. está disponível.
setEnPassant :: Int -> Int -> Jogo -> Jogo
setEnPassant x y jogo = jogo { enpassant = Just (x, y) }

-- Verifica se as coordenadas estão dentro da matriz 8x8.
dentroTab :: Int -> Int -> Bool
dentroTab x y = (0 <= x && x <= 7) && (0 <= y && y <= 7)


---
---- Coordenadas
---


-- Devolve a tupla de coordenadas da peça Rei de certo time. Se há um rei devove Just (Int, Int) senão Nothing.
coordRei :: Cor -> Jogo -> Maybe (Int, Int)
coordRei cor jogo = listToMaybe $ coordPecaTime jogo (Peca cor Rei)

-- lista coordenadas das peças de um time.
coordTime :: Cor -> Jogo -> [(Int, Int)]
coordTime cor jogo = [(x, y) | (Casa (x, y) pecaTab) <- casas, (evalPeca pecaTab)]
  where
    casas = concat $ tabuleiro jogo
    evalPeca Nothing = False
    evalPeca (Just (Peca corPeca _ )) = cor == corPeca

-- lista coordenadas das peças iguais a peca passada como argumento de um certo time.
coordPecaTime :: Jogo -> Peca -> [(Int, Int)]
coordPecaTime jogo peca = [(x, y) | (Casa (x, y) pecaTab) <- casas, pecaTab == Just peca]
  where
    casas = concat $ tabuleiro jogo


---
---- Verificação de Casa.
---


-- Inicia uma partida com 1º Turno para time Preto e um tabuleiro com configuração inicial.
-- Verifica se há uma peça nas coordenadas x y do tabuleiro, devolvendo Nothing para casa vazia ou Just (Peca Cor Classe).
verificaCasa :: Int -> Int -> Tabuleiro -> Maybe Peca
verificaCasa x y tab = peca
  where
    (Casa _ peca) = tab !! x !! y


---
---- Verificação de Movimentos.
---


-- validaMovClasse só verifica se o movimento é válido para a classe da peca, não verifica se é dentro do tabuleiro
-- e nenhuma outra condição que impediria o movimento. De acordo com a sua saída outra função irá verificar se
-- mov é valido para aquela classe de movimento.
validaMovClasse :: Int -> Int -> Int -> Int -> Jogo -> Maybe TipoMovimento
validaMovClasse x1 y1 x2 y2 jogo = verificaCasa x1 y1 tab >>= \x -> validaMovClassePeca x
  where
    tab = tabuleiro jogo
    -- Para a torre há a verificação de Roque.
    validaMovClassePeca (Peca _ Torre)  = if ((x1 == x2 && y1 /= y2) || (x1 /= x2 && y1 == y2))
                                      then Just (roqueValido x1 y1) else Nothing
    validaMovClassePeca (Peca _ Cavalo) = if (abs (x1 - x2) == 2) && (abs (y1 - y2) == 1)
                                      || (abs (x1 - x2) == 1) && (abs (y1 - y2) == 2)
                                      then Just Normal else Nothing
    validaMovClassePeca (Peca _ Bispo)  = if (abs (x1 - x2) == abs (y1 - y2))
                                      then Just Normal else Nothing
    -- Para o rei há verificação de Check.
    validaMovClassePeca (Peca _ Rei)    = if (abs (x1 - x2) <= 1) && (abs (y1 - y2) <= 1) && not (x2 == 0 && y2 == 0)
                                      then Just MovRei else Nothing
    validaMovClassePeca (Peca _ Rainha) = if (abs (x1 - x2)) == (abs (y1 - y2)) -- Diagonais
                                      || (x1 == x2 && y1 /= y2)                 -- Horizontal
                                      || (x1 /= x2 && y1 == y2)                 -- Vertical
                                      then Just Normal else Nothing
    -- Verificação de Peão será caso a caso.
    validaMovClassePeca (Peca Preto Peao)
      | x1 + 1 == x2 && y1 == y2           = Just Normal                       -- Anda 1 Casa.
      | x1 == 1 && x2 == 3 && y1 == y2     = Just MovInicialPeao               -- Anda 2 Casas de inicio.
      | x1 + 1 == x2 && (abs (y1 - y2) == 1)
        && isJust (verificaCasa x2 y2 tab) = Just Normal                       -- Captura (Sem ver se é do mesmo time).
      | enpassant jogo == Just (x2, y2) && (verificaCasa x1 y2 tab /= Nothing)
        && abs (x1 - x2) == 1 && abs (y1 - y2) == 1 = Just EnPassant           -- Faz En Passent.
      | otherwise = Nothing
    validaMovClassePeca (Peca Branco Peao)
      | x1 - 1 == x2 && y1 == y2           = Just Normal                       -- Anda 1 Casa.
      | x1 == 6 && x2 == 4 && y1 == y2     = Just MovInicialPeao               -- Anda 2 Casas de inicio.
      | x1 - 1 == x2 && (abs (y1 - y2) == 1)
        && isJust (verificaCasa x2 y2 tab) = Just Normal                       -- Captura (Sem ver se é do mesmo time).
      | enpassant jogo == Just (x2, y2) && (verificaCasa x1 y2 tab /= Nothing)
        && abs (x1 - x2) == 1 && abs (y1 - y2) == 1 = Just EnPassant           -- Faz En Passent.
      | otherwise = Nothing

-- validaMov - passo anterior do validaMovClasse. Nesta função tratamos as excessões, como espaço vazio, peça no caminho, etc.
-- Sua saída será ou um Left com o erro ou um right informando o tipo de mov que será feito.
validaMov :: Int -> Int -> Int -> Int -> Jogo -> Either MovInvalido TipoMovimento
validaMov x1 y1 x2 y2 jogo
  | isNothing $ verificaCasa x1 y1 tab = Left CasaVazia
  | corPeca /= turno jogo              = Left TurnoErrado
  | capturaProprio x2 y2 corPeca tab   = Left MesmoTime
  | pecaNoCaminho x1 y1 x2 y2 peca tab = Left SobrePeca
  | capturaPeaoErro y1 x2 y2 peca tab  = Left SobrePeca
  | otherwise = case validaMovClasse x1 y1 x2 y2 jogo of
                  Nothing -> Left MovInvalido
                  Just mov -> if check corPeca $ movSemChecar x1 y1 x2 y2 mov jogo
                              then if check corPeca jogo then Left EmCheck else Left FazCheck
                              else Right mov
  where
    tab = tabuleiro jogo
    -- \/ - Só da erro no caso Nothing quando utilizar peça, que não ocorre pois a verificação é feita antes.
    peca = fromJust $ verificaCasa x1 y1 tab
    corPeca = cor peca

-- Verifica se há tentative de capturar uma peça com um movimento reto de peão.
capturaPeaoErro :: Int -> Int -> Int -> Peca -> Tabuleiro -> Bool
capturaPeaoErro y1 x2 y2 peca tab = (classe peca == Peao) && y1 == y2 && (isJust $ verificaCasa x2 y2 tab)

-- Verifica se a peça na posição final é do mesmo time.
capturaProprio :: Int -> Int -> Cor -> Tabuleiro -> Bool
capturaProprio x y corPeca tab = case verificaCasa x y tab of
                   Just (Peca corP2 _) -> corP2 == corPeca
                   Nothing -> False

-- Verifica se existe alguma peça nas casas entre a posição inicial da peça e na posição final.
pecaNoCaminho :: Int -> Int -> Int -> Int -> Peca -> Tabuleiro -> Bool
pecaNoCaminho x1 y1 x2 y2 peca tab = case peca of
  (Peca _ Cavalo) -> False
  _ -> let (dx, dy) = (signum (x2 - x1), signum (y2 - y1)) -- Determina Quadrante.
           casas
                | dx == 0 = [(x1, yy) | yy <- [y1, y1 + dy..y2], yy /= y1, yy /= y2]
                | dy == 0 = [(xx, y1) | xx <- [x1, x1 + dx..x2], xx /= x1, xx /= x2]
                | otherwise = [(x1 + d * dx, y1 + d * dy) | d <- [1..(min (abs (y2 - y1)) (abs (x2 - x1))) - 1]]
       in any (\(x, y) -> isJust $ verificaCasa x y tab) casas

-- Movimento é válido somente quando a função validaMov Retornar um Right.
podeMover :: Int -> Int -> Int -> Int -> Jogo -> Bool
podeMover x1 y1 x2 y2 jogo = not $ isLeft $ validaMov x1 y1 x2 y2 jogo


---
---- Funções de Movimentações.
---


-- realiza um movimento e devolve um jogo com o movimento realizado.
movSemChecar :: Int -> Int -> Int -> Int -> TipoMovimento -> Jogo -> Jogo
movSemChecar x1 y1 x2 y2 mov jogo = case mov of
  -- Realiza o movimento, devolvendo um novo jogo, reseta o EnPassant neste jogo novo, troca o turno neste novo jogo.
  Normal -> trocaTurno $ resetEnPassant $ movePeca x1 y1 x2 y2 jogo
  -- Move Rei com mov. Normal, e retira a condição de Roque para ambos os lados.
  MovRei -> let (Peca cor _) = fromJust $ verificaCasa x1 y1 (tabuleiro jogo)
            in movSemChecar x1 y1 x2 y2 Normal (removeRoque (casoRoque cor "kq") jogo)

  -- Move Torre com mov. Normal, e retira a condição de Roque do lado do Rei.
  RoqueLadoRei -> let (Peca cor _) = fromJust $ verificaCasa x1 y1 (tabuleiro jogo)
                  in movSemChecar x1 y1 x2 y2 Normal (removeRoque (casoRoque cor "k") jogo)
  -- Move Torre com mov. Normal, e retira a condição de Roque do lado da Rainha.
  RoqueLadoRainha -> let (Peca cor _) = fromJust $ verificaCasa x1 y1 (tabuleiro jogo)
                     in movSemChecar x1 y1 x2 y2 Normal (removeRoque (casoRoque cor "q") jogo)
  -- Movimenta peão liberando a possibilidade do EnPassant.
  MovInicialPeao -> trocaTurno $ setEnPassant ((x1 + x2) `div` 2) y2 $ movePeca x1 y1 x2 y2 jogo
  -- Faz o movimento de EnPassant.
  EnPassant -> trocaTurno $ resetEnPassant $ movePeca x1 y1 x2 y2 $ removePeca x1 y2 jogo

-- Coloca a peça da pos. inicial na pos. final e então remove a peça na pos. inicial.
movePeca :: Int -> Int -> Int -> Int -> Jogo -> Jogo
movePeca x1 y1 x2 y2 jogo = removePeca x1 y1 $ colocaPeca (Casa (x2, y2) (verificaCasa x1 y1 (tabuleiro jogo))) jogo

-- Coloca uma peça Nothing na posição.
removePeca :: Int -> Int -> Jogo -> Jogo
removePeca x y jogo = colocaPeca (Casa (x, y) Nothing) jogo

-- Dada uma pos. e uma peça e jogo, devolve novo jogo com a casa desta pos. com esta nova peça.
colocaPeca :: Casa -> Jogo -> Jogo
colocaPeca casa jogo = jogo { tabuleiro = alteraCasa casa (tabuleiro jogo)}   -- tabuleiro jogo // [(Casa (x, y), peca)] } -- Da minha [[Casa]] trocar elem. (Cas (x,y) _) por (Casa (x,y) peca).

-- Altera um tabuleiro , colocando casa em sua posição (substitui a antiga)
alteraCasa :: Casa -> Tabuleiro -> Tabuleiro
alteraCasa casa@(Casa (x, y) _) tab = tabA <> [novaCasa] <> tabB
  where
    tabA = take x tab
    tabB = drop (x + 1) tab
    novaCasa = take y (tab !! x) <> [casa] <> drop (y + 1) (tab !! x)


---
---- Roque.
---


-- Retira da string sobre possíveis Roques aquele que não podem ser mais realizados.
removeRoque :: String -> Jogo -> Jogo
removeRoque c jogo = jogo { roqueDisponivel = (roqueDisponivel jogo) \\ c } -- Da minha lista de Char, retira ocorrências de c.

-- Maiúsculas representam time Branco, minúsculas o Preto. Para saber qual cos char retirar da string sobre Roque.
-- ex: se Branco moveu o Rei, devo retirar a possibilidade de Roque dos lado rei e rainha, assim remover da string 'Q' 'K'.
casoRoque :: Cor -> String -> String
casoRoque cor c
  | cor == Branco = map toUpper c
  | otherwise = map toLower c

-- Verifica se é possível realizar o movimento Roque, na perspectiva da Torre.
roqueValido :: Int -> Int -> TipoMovimento
roqueValido x1 y1
  | (x1 == 0 || x1 == 7) && y1 == 0 = RoqueLadoRainha
  | (x1 == 0 || x1 == 7) && y1 == 7 = RoqueLadoRei
  | otherwise                       = Normal

-- Verifica se para o jogador atual é possível realizar o mov. Roque para aquele lado do tabuleiro.
roquePermitido :: Jogo -> Classe -> Bool
roquePermitido jogo lado =
  verificaCasa x 4 tab == Just (Peca t Rei) &&
  all (\y -> isNothing $ verificaCasa x y tab) semPeca &&
  all (\x -> not $ check t $ movSemChecar x 4 x y Normal jogo) semCheck &&
  roqueDisp `elem` roqueDisponivel jogo
  where
    t = turno jogo
    tab = tabuleiro jogo
    x = if t == Branco then 7 else 0
    y = if lado == Rei then 7 else 0
    semPeca = if lado == Rei then [5,6] else [1,2,3]
    semCheck = if lado == Rei then [5,6] else [2,3]
    roqueDisp = (if t == Branco then id else toLower) (if lado == Rei then 'K' else 'Q')

-- Roque que irá executar o mesmo que move, mas movendo duas peças. No fim retorna Invalido caso não
-- seja permitido realizar o roque ou devolve o jogo atualizado com o mov. especial, atualizando a
-- disponibilidade do mov.
roque :: Jogo -> Classe -> Either MovInvalido Jogo
roque jogo lado
  | roquePermitido jogo lado = Right (resetRoque $ trocaTurno $ resetEnPassant $ moveRei $ moveTorre jogo)
  | otherwise = Left Invalido
  where
    t = turno jogoInicial
    x = if t == Branco then 7 else 0
    (torreY1, torreY2) = if lado == Rei then (7, 5) else (0, 3)
    (reiY1, reiY2) = if lado == Rei then (4, 6) else (4, 2)
    moveTorre jogo = movePeca x torreY1 x torreY2 jogo
    moveRei jogo = movePeca x reiY1 x reiY2 jogo
    resetRoque jogo = removeRoque (casoRoque t "kq") jogo


---
---- Promote.
---


-- Faz um alteraCasa, passando a Casa com classe escolhida, para cada char um
-- Verificação do caractere se dá na função que pede input do jogador.
fazPromote :: Char -> Jogo -> Jogo
fazPromote c jogo = promote x y c jogo
  where
    (x, y) = filter (\(x,_) -> x == 0) coordPeao !! 0
    coordPeao = coordPecaTime jogo (Peca cor Peao)
    cor = outraCor (turno jogo)

promote :: Int -> Int -> Char -> Jogo -> Jogo
promote x y c jogo
  | c == 'r' = jogo { tabuleiro = alteraCasa (Casa (x, y) (Just (Peca cor Rainha))) tab }
  | c == 'b' = jogo { tabuleiro = alteraCasa (Casa (x, y) (Just (Peca cor Bispo))) tab }
  | c == 'c' = jogo { tabuleiro = alteraCasa (Casa (x, y) (Just (Peca cor Cavalo))) tab }
  | c == 't' = jogo { tabuleiro = alteraCasa (Casa (x, y) (Just (Peca cor Torre))) tab }
  where
    tab = tabuleiro jogo
    (Peca cor _) = fromJust $ verificaCasa x y tab

-- existePromote - verifica se há promoção a ser feita depois do move, para fazer o getchar e o promote.
-- obs. Pego outra cor pois tenho um jogo atualizado, com o turno já alterado, mas quero verificar para o time
-- que fez o movimento.
existePromote :: Jogo -> Bool
existePromote jogo = case cor of
  Branco -> any (\(x, _) -> x == 0) coordPeao
  Preto ->  any (\(x, _) -> x == 7) coordPeao
  where
    coordPeao = coordPecaTime jogo (Peca cor Peao)
    cor = outraCor (turno jogo)


---
---- Condições de Jogo.
---


-- Verifica para uma certa cor se ele está em check para o estado atual do tabuleiro.
check :: Cor -> Jogo -> Bool
check cor jogo = case coordRei cor jogo of
  Just (kx, ky) -> any (\(x, y) -> podeMover x y kx ky jogoAux) outrasPecas
  Nothing -> False
  where
    outrasPecas = coordTime (outraCor cor) jogo
    jogoAux = jogo {turno = outraCor cor}

-- Devolve True se não há nenhum movimento disponível para o time.
reiAfogado :: Cor -> Jogo -> Bool
reiAfogado cor jogo = not $ any (== True) [ existeMovValido x y jogo | (x,y) <- coorT ]
  where
    coorT = coordTime cor jogo

-- Retorna True se há mov. válido para a peça na posição x1 y1.
existeMovValido :: Int -> Int -> Jogo -> Bool
existeMovValido x1 y1 jogo = any isRight [ validaMov x1 y1 x2 y2 jogo | x2 <- [0..7], y2 <- [0..7] ]

-- Se rei afogado e em check, portanto checkMate.
checkMate :: Cor -> Jogo -> Bool
checkMate cor jogo = check cor jogo && reiAfogado cor jogo


---
---- Realização de Movimento.
---


-- move : Devolve um Either MovInvalido (Left antes de aplicar o binding) ou um jogo (Faz o bind com o movType e passa para o movSemChecar)
move :: Int -> Int -> Int -> Int -> Jogo -> Either MovInvalido Jogo
move x1 y1 x2 y2 jogo = validaMov x1 y1 x2 y2 jogo >>= \tipoMov -> return (movSemChecar x1 y1 x2 y2 tipoMov jogo)

-- Receberá os valores de x1 y1 x2 y2 do jogador, tratará os casos de mov. especiais, validará os valores de
-- entrada para então realizar a função de movimento desejada, retornando um Left MovInvalido quando o
-- movimento não for possível ou um Right Jogo com a nova iteração para este, com o novo movimento.
-- Veja que quando realizar fromRight receberá o valor inicial do jogo e o Either deste jogo com o movimento
-- desejado, caso não seja possível será apresentado o erro para o jogador, e um novo turno idêntico será feito
-- utilizando o jogo inicial, caso contrário um novo turno será feito com o novo tabuleiro.
jogada :: String -> Jogo -> Either MovInvalido Jogo
jogada "RR" jogo = roque jogo Rei
jogada "RQ" jogo = roque jogo Rainha
jogada s jogo
  | length lc /= 4                      = Left Invalido
  | not (dentroTab x1 y1 && dentroTab x2 y2) = Left Invalido
  | otherwise                                = move x1 y1 x2 y2 jogo
  where
    lc = concat $ words s
--    numbers = map (\x -> read x :: Int) (words s)
    x1 = read ([lc !! 1]) :: Int
    y1 = if n == Nothing then 99 else fromJust n
      where
        n = elemIndex (lc !! 0) col
    x2 = read ([lc !! 3]) :: Int
    y2 = if n == Nothing then 99 else fromJust n
      where
        n = elemIndex (lc !! 2) col
    col = ['a','b','c','d','e','f','g','h']


---
---- Funções de Impressão de partida.
---


-- Função que imprime o tabuleiro com com, e apresentando a colina e linha de coordenadas.
printTab :: Jogo -> IO ()
printTab j = do putStrLn $ "Turno: Time " ++ show (turno j) ++ ".\n"
                if (enpassant j == Nothing)
                  then putStrLn $ ""
                  else putStrLn $ "\n --- EnPassant Disponível em (" ++ show (fst $ fromJust (enpassant j)) ++ " , " ++ show (snd $ fromJust (enpassant j)) ++ ").\n\n"
                putStrLn $ "    a   b   c   d   e   f   g   h "
                printCasas (tabuleiro j) 0

-- Função para imprimir o tabuleiro
printCasas :: Tabuleiro -> Int -> IO ()
printCasas [] _ = putStrLn $ ""
printCasas (x:xs) col = do putStr $ " " ++ show col ++ " "
                           mapM_ printCasaComCor x
                           putStrLn $ ""
                           printCasas xs (col + 1)

-- Função para imprimir a casa
printCasaComCor :: Casa -> IO ()
printCasaComCor c@(Casa (x,y) _)
  | (x+y) `mod` 2 == 0 = corFundo Green c
  | otherwise = corFundo White c
  where
    corFundo cor2 str = do
      setSGR [ SetConsoleIntensity BoldIntensity
             , SetColor Foreground Vivid Black
             , SetColor Background Dull cor2
             , SetPaletteColor Foreground $ xterm24LevelGray 0
             ]
      putStr (show str)
      setSGR [ Reset ]
