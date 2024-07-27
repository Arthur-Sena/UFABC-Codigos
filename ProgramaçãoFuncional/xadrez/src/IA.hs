module IA where

import Elementos
import Xadrez
import Data.Either
import Data.Maybe
import System.Random

-- Dado um jogo, função bem ineficiente que retorna um movimento em coordenadas para o jogador atual.
getMove :: Jogo -> IO String
getMove j = do g <- getStdGen
               let mov = movInt g
                   coord = geraCoord mov
               return $ coord
  where
    movInt g = getAleat g possMovs
    possMovs = catMaybes $ possiveisMovs j

-- Dado um gerador e uma lista, retorna um elem. aleatório desta lista.
getAleat :: StdGen -> [a] -> a
getAleat g lx = lx !! fst (randomR (0, length lx) g)

-- Dado um jogo, gera todos os mov. possíveis para o jogador do turno atual.
possiveisMovs :: Jogo -> [Maybe (Int, Int, Int, Int)]
possiveisMovs j = [ if valid x1 y1 x2 y2 then Just (x1,y1,x2,y2) else Nothing | x1 <- [0..7], y1 <- [0..7], x2 <- [0..7], y2 <- [0..7]]
  where
    valid x1 y1 x2 y2 = isRight $ validaMov x1 y1 x2 y2 j

-- Dada uma tupla com os valores iniciais e finais do mov. devolve uma string de coord.
geraCoord :: (Int, Int, Int, Int) -> String
geraCoord (x1, y1, x2, y2) = coord1 ++ " " ++ coord2
  where
    coord1 = [col !! y1] ++ show x1
    coord2 = [col !! y2] ++ show x2
    col = ['a','b','c','d','e','f','g','h']

-- Promoção sempre será a ideal na maioria dos casos, a rainha.
getCharPromo :: IO String
getCharPromo = return "q"
