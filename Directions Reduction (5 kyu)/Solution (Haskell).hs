module Codewars.Kata.Reduction where

import Codewars.Kata.Reduction.Direction

dirReduce :: [Direction] -> [Direction]
dirReduce = reverse . foldl reduce_opposite_directions []
    where
        reduce_opposite_directions :: [Direction] -> Direction -> [Direction]
        reduce_opposite_directions (previous_direction : other_directions) current_direction
            | opposite_directions previous_direction current_direction = other_directions
        reduce_opposite_directions other_directions current_direction = current_direction : other_directions

opposite_directions :: Direction -> Direction -> Bool
opposite_directions North South = True
opposite_directions South North = True
opposite_directions East West = True
opposite_directions West East = True
opposite_directions _  _ = False