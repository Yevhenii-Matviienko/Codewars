module Smile where

countSmileys :: [String] -> Int
countSmileys = length . filter (`elem` smileys)
    where
        smileys = [":)", ":D", ";)", ";D", ":-)", ":-D", ";-)", ";-D", ":~)", ":~D", ";~)", ";~D"]