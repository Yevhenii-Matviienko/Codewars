module RangeExtractor.JorgeVS.Kata where

import Data.List (intercalate)

solution :: [Integer] -> String
solution = intercalate "," . map format_output . foldr group_items []
    where
        group_items item_1 ((item_2 : items_group) : items)
            | item_1 + 1 == item_2 = (item_1 : item_2 : items_group) : items
        group_items x rest = [x] : rest
        format_output [item_1] = show item_1
        format_output [item_1, item_2] = show item_1 ++ "," ++ show item_2
        format_output items = show (head items) ++ "-" ++ show (last items)