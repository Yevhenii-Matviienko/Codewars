module EvenFibonacciSum (fibSum) where

fibSum :: Int -> Int
fibSum n = while 0 1 0
    where
        while :: Int -> Int -> Int -> Int
        while number_1 number_2 total_sum
            | number_1 >= n = total_sum
            | even number_1 = while number_2 (number_1 + number_2) (total_sum + number_1)
            | otherwise = while number_2 (number_1 + number_2) total_sum