function solution(array $list): string {
    $index = 0;
    $result = [];
    while ($index < count($list)) {
        $range_start = $list[$index];
        while ($index + 1 < count($list) && $list[$index + 1] === $list[$index] + 1) {
            $index++;
        }
        $range_end = $list[$index];
        if ($range_end - $range_start >= 2) {
            $result[] = $range_start . '-' . $range_end;
        } 
        elseif ($range_end - $range_start === 1) {
            $result[] = (string) $range_start;
            $result[] = (string) $range_end;
        } 
        else {
            $result[] = (string) $range_start;
        }
        $index++;
    }
    return implode(',', $result);
}