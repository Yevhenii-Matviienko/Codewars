module DescendingOrder where

import Data.List (sortBy)
import Data.Ord (Down (..), comparing)

descendingOrder :: Integer -> Integer
descendingOrder number =
    read (sortBy (comparing Down) (show number))