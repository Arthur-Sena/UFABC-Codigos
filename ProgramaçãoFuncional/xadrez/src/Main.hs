module Main where

import Jogo

main :: IO ()
main = inicializa >>= loop >>= finaliza
