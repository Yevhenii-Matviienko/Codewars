module Greed (score) where

score :: [Int] -> Int
score dice = sum [total_score die_value (die_value_count die_value dice) | die_value <- [1..6]]

die_value_count :: Int -> [Int] -> Int
die_value_count die_value dice = length (filter (== die_value) dice)

total_score :: Int -> Int -> Int
total_score 1 dice_amount
    | dice_amount >= 3 = 1000 + (dice_amount - 3) * 100
    | otherwise = dice_amount * 100
total_score 5 dice_amount
    | dice_amount >= 3 = 500 + (dice_amount - 3) * 50
    | otherwise = dice_amount * 50
total_score die_value dice_amount
    | dice_amount >= 3 = die_value * 100
    | otherwise = 0