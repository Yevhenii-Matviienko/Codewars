function mix($s1, $s2) {
    $result_parts = [];
    for ($ascii_code = ord('a'); $ascii_code <= ord('z'); $ascii_code++) {
        $letter = chr($ascii_code);
        $count_letter_1 = substr_count($s1, $letter);
        $count_letter_2 = substr_count($s2, $letter);
        $max_count_letter = max($count_letter_1, $count_letter_2);
        if ($max_count_letter <= 1) {
            continue;
        }
        if ($count_letter_1 > $count_letter_2) {
            $prefix = '1:';
        } 
        elseif ($count_letter_2 > $count_letter_1) {
            $prefix = '2:';
        } 
        else {
            $prefix = '=:';
        }
        $result_parts[] = $prefix . str_repeat($letter, $max_count_letter);
    }
    usort($result_parts, function ($first_result_part, $second_result_part) {
        $length_difference = strlen($second_result_part) - strlen($first_result_part);
        if ($length_difference !== 0) {
            return $length_difference;
        }
        return strcmp($first_result_part, $second_result_part);
    });
    return implode('/', $result_parts);
}