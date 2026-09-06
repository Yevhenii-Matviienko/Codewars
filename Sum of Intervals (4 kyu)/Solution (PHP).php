function sum_intervals(array $intervals): int {
    if (!$intervals) {
        return 0;
    }
    sort($intervals);
    [$current_start, $current_end] = $intervals[0];
    $total_length = 0;
    foreach (array_slice($intervals, 1) as [$next_start, $next_end]) {
        if ($next_start <= $current_end) {
            $current_end = max($current_end, $next_end);
        } 
        else {
            $total_length += $current_end - $current_start;
            [$current_start, $current_end] = [$next_start, $next_end];
        }
    }
    return $total_length + $current_end - $current_start;
}