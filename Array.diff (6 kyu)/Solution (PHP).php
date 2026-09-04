function arrayDiff(array $a, array $b): array {
    return array_values(array_filter($a, fn($element) => !in_array($element, $b, true)));
}