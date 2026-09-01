module Codewars.Kata.TenMinuteWalk where

isValidWalk :: [Char] -> Bool
isValidWalk walk = length (take 11 walk) == 10 &&
    count 'n' == count 's' &&
    count 'e' == count 'w'
    where
        count direction = length (filter (== direction) walk)