function digital_root(int $number): int {
    while ($number >= 10) {
        $digits = str_split((string) $number);
        $number = array_sum($digits);
    }
    return $number;
}