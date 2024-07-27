module Elementos where

data Jogo = Jogo { turno :: Cor
                 , roqueDisponivel :: String -- String como por ex. "kq" simbolizando Roque disp. ambos lados para time Preto.
                 , enpassant :: Maybe (Int, Int) -- captura peão logo após 2 mov se movendo para a casa atrás deste peão.
                 , tabuleiro :: Tabuleiro
                 } deriving (Eq)

type Tabuleiro = [[Casa]]

data Casa      = Casa { pos :: (Int, Int)
                      , peca :: (Maybe Peca)
                      } deriving (Eq)

data Peca = Peca { cor :: Cor
                 , classe :: Classe
                 } deriving (Eq)

data Cor       = Branco | Preto deriving (Show, Eq)

data Classe    = Peao | Torre | Bispo
               | Cavalo | Rainha | Rei deriving (Show, Eq)


data TipoMovimento = Normal | MovRei | RoqueLadoRei
                   | RoqueLadoRainha | MovInicialPeao
                   | EnPassant deriving (Show, Eq)

data MovInvalido = MovInvalido  | EmCheck   | FazCheck
                 | CasaVazia | SobrePeca | TurnoErrado
                 | MesmoTime | Invalido deriving (Show, Eq)


---
---- Instances.
---


instance Show Jogo where
  show jogo = turn ++ enpass ++ tab
    where
      t = tabuleiro jogo
      turn = "\nTurno:  Time " ++ show (turno jogo) ++ ".\n\n"
      enpass = case enpassant jogo of
        Nothing -> ""
        Just (x, y) -> "\n --- EnPassant Disponível em ( " ++ show x ++ " , " ++ show y ++ " ).\n\n"
      tab = map (\x -> trocaChar x) $ unlines $ map show t
      trocaChar x = case x of
        '[' -> '|'
        ']' -> '|'
        ',' -> ' '
        _ -> x

instance Ord Casa where
  (Casa (x1, y1) _) <= (Casa (x2, y2) _)
    | x1 > x2 = False
    | x1 < x2 = True
    | y1 > y2 = False
    | otherwise = True

instance Show Casa where
  show (Casa po Nothing) = "    "
  show (Casa po (Just pe))  = show pe

instance Show Peca where
  show (Peca Branco Torre) = " ♖  "
  show (Peca Preto Torre) = " ♜  "

  show (Peca Branco Rei) = " ♔  "
  show (Peca Preto Rei) = " ♚  "

  show (Peca Branco Peao) = " ♙  "
  show (Peca Preto Peao) = " ♟  "

  show (Peca Branco Bispo) = " ♗  "
  show (Peca Preto Bispo) = " ♝  "

  show (Peca Branco Cavalo) = " ♘  "
  show (Peca Preto Cavalo) = " ♞  "

  show (Peca Branco Rainha) = " ♕  "
  show (Peca Preto Rainha) = " ♛  "
