module Kata (highAndLow) where

highAndLow :: String -> String
highAndLow input =
    let numbers = map (\number -> read number :: Int) (words input)
    in show (maximum numbers) ++ " " ++ show (minimum numbers)