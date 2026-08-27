module Triangular where

triangular :: Integer -> Integer
triangular n
    | n > 0 = n * (n + 1) `div` 2
    | otherwise = 0