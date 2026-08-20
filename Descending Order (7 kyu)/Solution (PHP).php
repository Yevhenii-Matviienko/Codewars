function descendingOrder(int $n): int {
    $digits = str_split((string)$n);
    rsort($digits);
    return (int)implode('', $digits);
}