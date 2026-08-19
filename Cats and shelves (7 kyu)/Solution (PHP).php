<?php

function cats(int $start, int $finish): int {
    $shelves_difference = $finish - $start;
    return intdiv($shelves_difference, 3) + $shelves_difference % 3;
}