module JogoM where

import Elementos
import Xadrez
import Data.Either
import Network.Socket
import qualified Data.ByteString.Char8 as C
import Network.Socket.ByteString

data Jogador = Host | Client deriving (Eq)


-- Recebe uma conexão e a informação sobre quem é o jogador (host ou cliente) e então passa uma
-- configuração inicial de jogo para a função loop, que realiza cada turn da partida.
inicializa :: (Socket, Jogador) -> IO (Jogo, Socket, Jogador)
inicializa (s, jogador) =  do tutorial <- readFile "Tutorial"
                              putStrLn $ tutorial
                              return (jogoInicial, s, jogador)


{- Função principal do programa. Recebe um estado de jogo, uma conexão e uma informação do jogador.
   A primeira parte da função consiste em informar os jogadores sobre condições importantes sobre
a partida para este determinar o melhor movimento, como se está em check ou há roque disponível.
   Em seguida de acordo com o turno, ou o jogador aguarda a descisão dou outro jogador ou ele informa
as coordenadas do movimento desejado. Está é a parte que utilizará uma conexão.
   Após o movimento temos que verificar se há a possibilidade de uma promoção, caso haja uma nova conversa
deverá ser feita para o jogador descidir a promoção e informar o outro jogador sobre ela.
   Passando a verificação e tratamento da promoção, então verificasse as condições pós movimento, onde
caso verdadeiras simboliza o término da partida, saindo então do loop da função de turnos.
   Caso não haja uma condição de término, então o loop é refeito para o meu novo estado de jogo, progredindo
assim com minha partida.
-}
loop :: (Jogo, Socket, Jogador) -> IO (Jogo, Jogador)
loop (jx, s, jogador) = do
  -- Condições essenciais para tomada decisão do movimento.
  putStrLn $ avisoPreJogo
  -- Apresenta o jogo e aguarda a entrada das coordenadas.
  printTab jx
  putStrLn $ "Digite as coord. do movimento:\n"
  --- Bloco Input c/ rede.
  ---------------------------------------------------------------------
  input <- if ( turno jx == Branco ) -- CLient envia msg, host recebe.
             then if ( jogador == Client)
                  then do msg <- getLine
                          sendAll s $ C.pack msg
                          return msg
                  else do putStrLn $ "Aguardando jogada do oponente...\n"
                          msg <- recv s 1024
                          return $ C.unpack msg
             else if ( jogador == Host) -- Client recebe, host envia.
                  then do msg <- getLine
                          sendAll s $ C.pack msg
                          return msg
                  else do putStrLn $ "Aguardando jogada do oponente...\n"
                          msg <- recv s 1024
                          return $ C.unpack msg
  ---------------------------------------------------------------------
  rx1 <- return $ jogada input jx
  -- Informa sobre possíveis erros com o valor de entrada.
  if (isLeft rx1)
    then putStrLn $ infoErro $ fromLeft Invalido rx1
    else putStrLn $ ""
  jxi <- return $ fromRight jx rx1 -- Caso haja erro refaz o turno.
  -- Verifica Promoção, se possível aguarda input para atualizar jogo.
  jx1 <- if (existePromote jxi)
         then do putStrLn $ infoPromo
                 --- Bloco Input c/ rede
                 ------------------------------------------------------------------------------
                 charPromo <- if ( turno jx == Branco ) -- CLient envia msg, host recebe.
                   then if ( jogador == Client)
                   then do msg <- getLine
                           sendAll s $ C.pack msg
                           return msg
                   else do putStrLn $ "Aguardando promoção do oponente...\n"
                           msg <- recv s 1024
                           return $ C.unpack msg
                   else if ( jogador == Host) -- Client recebe, host envia.
                   then do msg <- getLine
                           sendAll s $ C.pack msg
                           return msg
                   else do putStrLn $ "Aguardando promoção do oponente...\n"
                           msg <- recv s 1024
                           return $ C.unpack msg
                 ------------------------------------------------------------------------------
                 if (charPromoInvalid charPromo)
                   then do putStrLn $ "\n --- Promo invalida, refaça a jogada:\n"
                           return jx
                   else return $ fazPromote (charPromo !! 0) jxi
         else return jxi
  -- Verifica condições depois de move (CheckMate e Afogamento).
  if (checkMate (turno jx1) jx1)
    then return (jx1, jogador)
    else if (reiAfogado (turno jx1) jx1)
    then return (jx1, jogador)
    else loop (jx1, s, jogador)
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
finaliza :: (Jogo, Jogador) -> IO ()
finaliza (jFinalizado, jogador) =
  do if (checkMate (turno jFinalizado) jFinalizado)
       then case turno jFinalizado of
              Branco -> if (jogador == Host) then do putStrLn $ "\nParabéns, você venceu !!!"
                                                     printTab jFinalizado
                        else do putStrLn $ "\nVocê perdeu, mas sempre existe uma próxima vez. Não desista !!!"
                                printTab jFinalizado
              Preto -> if (jogador == Client) then do putStrLn $ "\nParabéns, você venceu !!!"
                                                      printTab jFinalizado

                       else do putStrLn $ "\nVocê perdeu, mas sempre existe uma próxima vez. Não desista !!!"
                               printTab jFinalizado
     else if (reiAfogado (turno jFinalizado) jFinalizado)
     then putStrLn $ show jFinalizado ++ "\nJogo empatado por estado de Rei afogado.\n"
     else putStrLn $ "\nJogo Finalizado por motivos desconhecidos.\n"
     return ()


---
---- Auxiliares
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
  MovInvalido -> "\n --- Movimento errado para esta peça."
  EmCheck -> "\n --- Movimento não retira a condição de check."
  FazCheck -> "\n --- Movimento gera um check para o próprio time."
  CasaVazia -> "\n --- Por favor, forneça um par de coordenadas inicial com uma peça do seu time."
  SobrePeca -> "\n --- Movimento tenta passar sobre uma peça."
  TurnoErrado -> "\n --- Peça escolhida não é do seu time."
  MesmoTime -> "\n --- Tentativa de captura de uma peça do mesmo time."
  Invalido -> "\n --- Por favor, digite uma sequência como descrita no inicio da partida."
