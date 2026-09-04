function same_structure_as(array $a, array $b): bool {
    if (count($a) !== count($b)) {
        return false;
    }
    foreach ($a as $index => $element_array_a) {
        $element_array_b = $b[$index];
        if (is_array($element_array_a) !== is_array($element_array_b)) {
            return false;
        }
        if (is_array($element_array_a) && !same_structure_as($element_array_a, $element_array_b)) {
            return false;
        }
    }
    return true;
}