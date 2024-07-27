module Main where

import JogoMIA
import Control.Concurrent (forkFinally)
import qualified Control.Exception as E
import Control.Monad (unless, forever, void)
import qualified Data.ByteString as S
import qualified Data.ByteString.Char8 as C
import Network.Socket


main :: IO ()
main = do putStrLn $ "Aguardando conexão."
          runTCPServer Nothing "13033" jogo
  where
    jogo s = do inicializa (s, Host) >>= loop >>= finaliza

-- Função extraída do pacote "Network.Run.TCP" para abrir um host de conexão TCP.
runTCPServer :: Maybe HostName -> ServiceName -> (Socket -> IO a) -> IO a
runTCPServer mhost port server = withSocketsDo $ do
    addr <- resolve
    E.bracket (open addr) close loop
  where
    resolve = do
        let hints = defaultHints {
                addrFlags = [AI_PASSIVE]
              , addrSocketType = Stream
              }
        head <$> getAddrInfo (Just hints) mhost (Just port)
    open addr = E.bracketOnError (openSocket addr) close $ \sock -> do
        setSocketOption sock ReuseAddr 1
        withFdSocket sock setCloseOnExecIfNeeded
        bind sock $ addrAddress addr
        listen sock 1024
        return sock
    loop sock = forever $ E.bracketOnError (accept sock) (close . fst)
              $ \(conn, _peer) -> void $ forkFinally (server conn) (const $ gracefulClose conn 5000)

openSocket = \addr -> socket (addrFamily addr) (addrSocketType addr) (addrProtocol addr)
