<?php

function highAndLow(string $numbers): string {
    $numbers_array = array_map('intval', explode(' ', $numbers));
    return max($numbers_array) . ' ' . min($numbers_array);
}