function sum_strings($a, $b) {
    $index_1 = strlen($a) - 1;
    $index_2 = strlen($b) - 1;
    $carry = 0;
    $result = '';
    while ($index_1 >= 0 || $index_2 >= 0 || $carry > 0) {
        $digit_string_1 = $index_1 >= 0 ? ord($a[$index_1]) - ord('0') : 0;
        $digit_string_2 = $index_2 >= 0 ? ord($b[$index_2]) - ord('0') : 0;
        $total_digits_sum = $digit_string_1 + $digit_string_2 + $carry;
        $result .= (string) ($total_digits_sum % 10);
        $carry = intdiv($total_digits_sum, 10);
        $index_1--;
        $index_2--;
    }
    $answer = ltrim(strrev($result), '0');
    return $answer === '' ? '0' : $answer;
}