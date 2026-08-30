module Codewars.Kata.Fib where

productFib :: Integer -> (Integer, Integer, Bool)
productFib prod = find_numbers_Fibonacci 0 1 prod

find_numbers_Fibonacci :: Integer -> Integer -> Integer -> (Integer, Integer, Bool)
find_numbers_Fibonacci number_1 number_2 product
    | number_1 * number_2 >= product = (number_1, number_2, number_1 * number_2 == product)
    | otherwise = find_numbers_Fibonacci number_2 (number_1 + number_2) product