module Codewars.Kata.Square where

isSquare :: Integral n => n -> Bool
isSquare n
    | n < 0 = False
    | otherwise = square_root * square_root == n
    where square_root = floor (sqrt (fromIntegral n :: Double))