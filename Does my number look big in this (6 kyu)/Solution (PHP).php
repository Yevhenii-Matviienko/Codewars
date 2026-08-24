function narcissistic(int $value): bool {
    $digits = str_split((string) $value);
    $power = count($digits);
    $sum = 0;
    foreach ($digits as $digit) {
        $sum += (int) $digit ** $power;
    }
    return $sum === $value;
}