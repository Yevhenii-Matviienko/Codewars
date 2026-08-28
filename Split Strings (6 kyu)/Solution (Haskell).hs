module Codewars.Kata.SplitStrings where

solution :: String -> [String]
solution [] = []
solution [x] = [[x, '_']]
solution (x1 : x2 : xn) = [x1, x2] : solution xn