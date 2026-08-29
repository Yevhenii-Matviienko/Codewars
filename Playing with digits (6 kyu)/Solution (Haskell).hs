module Codewars.Kata.DigPow where

digpow :: Integer -> Integer -> Integer
digpow n p
    | total_sum `mod` n == 0 = total_sum `div` n
    | otherwise = -1
    where
        digits = map (read . (:[])) (show n)
        total_sum = sum (zipWith (^) digits [p..])