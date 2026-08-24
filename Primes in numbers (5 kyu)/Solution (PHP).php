function primeFactors($n) {
    $divisor = 2;
    $result = '';
    while ($divisor <= intdiv($n, $divisor)) {
        $count_divisions = 0;
        while ($n % $divisor === 0) {
            $count_divisions++;
            $n = intdiv($n, $divisor);
        }
        if ($count_divisions === 1) {
            $result .= "($divisor)";
        } 
        elseif ($count_divisions > 1) {
            $result .= "($divisor**$count_divisions)";
        }
        $divisor++;
    }
    if ($n > 1) {
        $result .= "($n)";
    }
    return $result;
}
