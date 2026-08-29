module Kata (findOutlier) where

findOutlier :: [Int] -> Int
findOutlier xs =
    if length even_numbers == 1
    then head even_numbers
    else head odd_numbers
    where
        even_numbers = filter even xs
        odd_numbers = filter odd xs