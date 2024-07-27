{-# LANGUAGE OverloadedStrings #-}
module Main where

import JogoM
import qualified Control.Exception as E
import qualified Data.ByteString.Char8 as C
import Network.Socket
import Network.Socket.ByteString (recv, sendAll)
import System.Environment


main :: IO ()
main = getIP >>= \ip -> runTCPClient ip "13033" jogo
  where
    jogo s = do inicializa (s, Client) >>= loop >>= finaliza

-- Função que pega argumento de execução de cliente e passa como o endereço IP do host.
getIP :: IO String
getIP = do arg <- getArgs
           let ip = concat arg
           return $ ip


-- Função extraída do pacote "Network.Run.TCP" para abrir uma conexão TCP de cliente a um host.
runTCPClient :: HostName -> ServiceName -> (Socket -> IO a) -> IO a
runTCPClient host port client = withSocketsDo $ do
    addr <- resolve
    E.bracket (open addr) close client
  where
    resolve = do
        let hints = defaultHints { addrSocketType = Stream }
        head <$> getAddrInfo (Just hints) (Just host) (Just port)
    open addr = E.bracketOnError (openSocket addr) close $ \sock -> do
        connect sock $ addrAddress addr
        return sock

openSocket = \addr -> socket (addrFamily addr) (addrSocketType addr) (addrProtocol addr)
