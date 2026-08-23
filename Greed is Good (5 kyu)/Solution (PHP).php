function score($dice) {
    $total_score = 0;
    for ($die_value = 1; $die_value <= 6; $die_value++) {
        $die_value_count = count(array_filter($dice, fn($die) => $die === $die_value));
        if ($die_value_count >= 3) {
            $total_score += $die_value === 1 ? 1000 : $die_value * 100;
            $die_value_count -= 3;
        }
        if ($die_value === 1) {
            $total_score += $die_value_count * 100;
        }
        if ($die_value === 5) {
            $total_score += $die_value_count * 50;
        }
    }
    return $total_score;
}