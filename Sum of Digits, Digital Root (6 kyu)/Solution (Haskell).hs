module DigitalRoot where

digitalRoot :: Integral number => number -> number
digitalRoot 0 = 0
digitalRoot number = (number - 1) `mod` 9 + 1