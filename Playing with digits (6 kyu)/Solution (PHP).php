function digPow($n, $p) {
    $sum = 0;
    foreach (str_split((string) $n) as $digit) {
        $sum += (int) $digit ** $p;
        $p++;
    }
    return $sum % $n === 0 ? intdiv($sum, $n) : -1;
}
