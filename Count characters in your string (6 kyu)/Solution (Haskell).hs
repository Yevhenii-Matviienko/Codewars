module Count (count) where

import Data.List (group, sort)

count :: String -> [(Char,Int)]
count str = map (\group_symbols -> (head group_symbols, length group_symbols)) (group (sort str))