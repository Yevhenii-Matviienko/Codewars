function count_smileys($arr): int {
    $smileys_counter = 0;
    foreach ($arr as $smiley) {
        if (preg_match('/^[:;][-~]?[)D]$/', $smiley)) {
            $smileys_counter++;
        }
    }
    return $smileys_counter;
}