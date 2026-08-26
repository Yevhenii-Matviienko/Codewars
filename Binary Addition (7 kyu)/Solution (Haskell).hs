module AddBinary (addBinary) where

import Data.Char (intToDigit)
import Numeric (showIntAtBase)

addBinary :: Int -> Int -> String
addBinary a b =
    (((showIntAtBase 2) intToDigit) (a + b)) ""