function justify(string $str, int $len): string {
    if (trim($str) === '') {
        return '';
    }
    $words = preg_split('/\s+/', trim($str));
    $line = [];
    $line_words_length = 0;
    $result = [];
    foreach ($words as $word) {
        if ($line_words_length + count($line) + strlen($word) > $len) {
            $result[] = format($line, $len);
            $line = [];
            $line_words_length = 0;
        }
        $line[] = $word;
        $line_words_length += strlen($word);
    }
    $result[] = implode(' ', $line);
    return implode("\n", $result);
}

function format(array $line, int $width): string {
    if (count($line) === 1) {
        return $line[0];
    }
    $symbols = 0;
    foreach ($line as $word) {
        $symbols += strlen($word);
    }
    $gaps = count($line) - 1;
    $spaces = $width - $symbols;
    $result = '';
    foreach ($line as $index => $word) {
        $result .= $word;
        if ($index < $gaps) {
            $count_spaces = intdiv($spaces, $gaps);
            if ($index < $spaces % $gaps) {
                $count_spaces++;
            }
            $result .= str_repeat(' ', $count_spaces);
        }
    }
    return $result;
}