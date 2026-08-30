module Codewars.Kata.BouncingBall where

bouncingBall :: Double -> Double -> Double -> Integer
bouncingBall h bounce window
    | h <= 0 || bounce <= 0 || bounce >= 1 || window >= h = -1
    | otherwise = count_ball_bounces (h * bounce) bounce window 1

count_ball_bounces :: Double -> Double -> Double -> Integer -> Integer
count_ball_bounces height bounce window ball_seen
    | height > window = count_ball_bounces (height * bounce) bounce window (ball_seen + 2)
    | otherwise = ball_seen