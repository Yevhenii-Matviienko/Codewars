module Narcissistic where

import Data.Char (digitToInt)

narcissistic :: Integral number => number -> Bool
narcissistic number = sum [toInteger (digitToInt digit) ^ power | digit <- digits] == toInteger number
    where 
        digits = show (toInteger number)
        power = length digits