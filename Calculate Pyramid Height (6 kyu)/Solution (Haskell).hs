module Kata (pyramidHeight) where

pyramidHeight :: Int -> Int
pyramidHeight n = length $ takeWhile (<= n) $ scanl1 (+) [block * block | block <- [1..]]