module Codewars.Kata.PrFactors where

import Data.List (group)

prime_factors :: Integer -> String
prime_factors n = concatMap format_output (group (find_divisors n 2))
    where
        find_divisors 1 _ = []
        find_divisors number divisor
            | divisor * divisor > number = [number]
            | number `mod` divisor == 0 = divisor : find_divisors (number `div` divisor) divisor
            | otherwise = find_divisors number (divisor + 1)
        format_output prime_numbers
            | length prime_numbers == 1 = "(" ++ show (head prime_numbers) ++ ")"
            | otherwise = "(" ++ show (head prime_numbers) ++ "**" ++ show (length prime_numbers) ++ ")"