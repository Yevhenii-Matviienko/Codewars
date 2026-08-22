function decode_morse(string $code): string {
    $words = explode('   ', trim($code));
    $result = '';
    foreach ($words as $word) {
        $letters = explode(' ', $word);
        foreach ($letters as $letter) {
            $result .= MORSE_CODE[$letter];
        }
        $result .= ' ';
    }
    return trim($result);
}