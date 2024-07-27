module Jogo where

import Elementos
import Xadrez
import Data.Either

-- Passa uma configuração inicial de jogo para a função loop, que realiza cada turn da partida.
inicializa :: IO Jogo
inicializa = {-\s -> --}do tutorial <- readFile "Tutorial"
                           putStrLn $ tutorial
                           return jogoInicial


{- Função principal do programa que recebe um estado de jogo e realiza os turnos da partida.
   A primeira parte da função consiste em informar os jogadores sobre condições importantes sobre
a partida para este determinar o melhor movimento, como se está em check ou há roque disponível.
   Em seguida o jogador informa as coordenadas do movimento desejado para seu time.
   Após o movimento temos que verificar se há a possibilidade de uma promoção, caso haja então
uma nova solicitação de entrada será realizada para informar qual a promoção desejada.
   Passando a verificação e tratamento da promoção, então verificasse as condições pós movimento, onde
caso verdadeiras simboliza o término da partida, saindo então do loop da função de turnos.
   Caso não haja uma condição de término, então o loop é refeito para o meu novo estado de jogo, progredindo
assim com a partida.
-}
loop :: Jogo -> IO Jogo
loop jx = do
  -- Condições essenciais para tomada decisão do movimento.
  putStrLn $ avisoPreJogo
  -- Apresenta o jogo e aguarda a entrada das coordenadas.
  printTab jx
  putStrLn $ "Digite as coord. do movimento:\n"
  --- Bloco Input
  --------------------------------------------------------------
  input <- getLine
  --------------------------------------------------------------
  rx1 <- return $ jogada input jx
  -- Informa sobre possíveis erros com o valor de entrada.
  if (isLeft rx1)
    then putStrLn $ infoErro $ fromLeft Invalido rx1
    else putStrLn $ ""
  jxi <- return $ fromRight jx rx1 -- Caso haja erro refaz o turno.
  -- Verifica Promoção, se possível aguarda input para atualizar jogo.
  jx1 <- if (existePromote jxi)
         then do putStrLn $ infoPromo
                 --- Bloco Input
                 --------------------------------------------------------------------
                 charPromo <- getLine
                 --------------------------------------------------------------------
                 if (charPromoInvalid charPromo)
                   then do putStrLn $ "\n --- Promo invalida, refaça a jogada:\n"
                           return jx
                   else return $ fazPromote (charPromo !! 0) jxi
         else return jxi
  -- Verifica condições depois de move (CheckMate e Afogamento).
  if (checkMate (turno jx1) jx1)
    then return jx1
    else if (reiAfogado (turno jx1) jx1)
    then return jx1
    else loop jx1
  where
    avisoPreJogo = estaEmCheck ++ roqueDisp
    estaEmCheck
      | check (turno jx) jx = "\n --- Em Check.\n"
      | otherwise           = ""
    roqueDisp
      | roquePermitido jx Rei && roquePermitido jx Rainha = "\n---Roque disponível em ambos os lados.\n - Comando : Lado Rei \"Roque Rei\"\n             Lado Rainha \"Roque Rainha\"\n"
      | roquePermitido jx Rei = "\n --- Roque disponível do lado Rei:\n - Comando : RR\n"
      | roquePermitido jx Rainha = "\n --- Roque disponível do lado Rainha:\n - Comando : RQ\n"
      | otherwise = ""
    infoPromo = " --- Há promoção disponível. Digite o digito da promoção desejada:\n 't' - Torre  'c' - Cavalo  'b' - Bispo  'r' - Rainha\n"

-- Parte final do programa, informando se jogador venceu ou perdeu, e finaliza o processo.
finaliza :: Jogo -> IO ()
finaliza jFinalizado = do if (checkMate (turno jFinalizado) jFinalizado)
                            then case turno jFinalizado of
                                   Branco -> do printTab jFinalizado
                                                putStrLn $ "Parabéns Time Preto, você venceu!\n"
                                   Preto -> do printTab jFinalizado
                                               putStrLn $ "Parabéns Time Branco, você venceu!\n"
                            else if (reiAfogado (turno jFinalizado) jFinalizado)
                            then do printTab jFinalizado
                                    putStrLn $ "Jogo empatado por estado de Rei afogado.\n"
                            else putStrLn $ "Jogo Finalizado por motivos desconhecidos.\n"
                          return ()


---
---- Auxiliares.
---

-- Dada uma entrada, verifica se é uma string de único caracter válido para promoção.
charPromoInvalid :: String -> Bool
charPromoInvalid s
  | length s /= 1 = True
  | not $ c `elem` listPromo = True
  | otherwise = False
  where
    c = s !! 0
    listPromo = "tbcr"

-- Informa sobre qual problema o movimento em questão ocasionou.
infoErro :: MovInvalido -> String
infoErro err = case err of
  MovInvalido -> "\n---Movimento errado para esta peça."
  EmCheck -> "\n --- Movimento não retira a condição de check."
  FazCheck -> "\n --- Movimento gera um check para o próprio time."
  CasaVazia -> "\n --- Por favor, forneça um par de coordenadas inicial com uma peça do seu time."
  SobrePeca -> "\n --- Movimento tenta passar sobre uma peça."
  TurnoErrado -> "\n --- Peça escolhida não é do seu time."
  MesmoTime -> "\n --- Tentativa de captura de uma peça do mesmo time."
  Invalido -> "\n --- Por favor, digite uma sequência como descrita no inicio da partida."
