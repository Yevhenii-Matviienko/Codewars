module Codewars.G964.Mixin where

import Data.List (sortOn, intercalate)

mix :: String -> String -> String
mix s1 s2 = intercalate "/" $ sortOn sort_groups_rule groups
    where
        groups = [get_prefix count_all_letters_1 count_all_letters_2 ++ ":" ++ replicate (max count_all_letters_1 count_all_letters_2) letter 
            | letter <- ['a'..'z'], 
            let count_all_letters_1 = count_all_letters letter s1, 
            let count_all_letters_2 = count_all_letters letter s2, 
            max count_all_letters_1 count_all_letters_2 > 1]
        count_all_letters letter = length . filter (== letter)
        get_prefix number_letters_1 number_letters_2
            | number_letters_1 > number_letters_2 = "1"
            | number_letters_2 > number_letters_1 = "2"
            | otherwise = "="
        sort_groups_rule group = (-length group, group)