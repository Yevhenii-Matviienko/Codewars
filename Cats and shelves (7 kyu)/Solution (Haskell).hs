module CatsAndShelves (solve) where

solve :: Word -> Word -> Word
solve start finish =
    shelves_difference `div` 3 + shelves_difference `mod` 3
    where shelves_difference = finish - start