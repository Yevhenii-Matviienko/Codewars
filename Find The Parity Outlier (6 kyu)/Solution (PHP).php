function find($integers) {
    $even_numbers = [];
    $odd_numbers = [];
    foreach ($integers as $integer) {
        if ($integer % 2 === 0) {
            $even_numbers[] = $integer;
        } 
        else {
            $odd_numbers[] = $integer;
        }
    }
    return count($even_numbers) === 1 ? $even_numbers[0] : $odd_numbers[0];
}