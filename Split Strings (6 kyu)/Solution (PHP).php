function solution($str) {
    if ($str === '') {
        return [];
    }
    if (strlen($str) % 2 !== 0) {
        $str .= '_';
    }
    return str_split($str, 2);
}