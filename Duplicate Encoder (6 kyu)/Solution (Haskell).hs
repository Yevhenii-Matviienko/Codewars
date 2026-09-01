module Dups where

import Data.Char (toLower)

duplicateEncode :: String -> String
duplicateEncode word = [if length (filter (== symbol) word_lowercase) > 1 then ')' else '(' | symbol <- word_lowercase]
    where
        word_lowercase = map toLower word