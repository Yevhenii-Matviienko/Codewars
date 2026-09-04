module Codewars.Kata.DecodeMorse (decodeMorse) where

import Codewars.Kata.DecodeMorse.Preload (morseCodes)
import Data.Map.Strict ((!))
import Data.List (dropWhileEnd)
import Data.List.Split (splitOn)

decodeMorse :: String -> String
decodeMorse morse = unwords [concatMap (morseCodes !) (words word) | word <- splitOn "   " (trim_start_end_gaps morse)]
    where 
        trim_start_end_gaps = dropWhileEnd (== ' ') . dropWhile (== ' ')