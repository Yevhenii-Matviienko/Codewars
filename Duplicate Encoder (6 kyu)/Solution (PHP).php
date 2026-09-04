function duplicate_encode(string $word): string {
    $word = strtolower($word);
    $result = "";
    for ($index = 0; $index < strlen($word); $index++) {
        $result .= substr_count($word, $word[$index]) > 1 ? ")" : "(";
    }
    return $result;
}