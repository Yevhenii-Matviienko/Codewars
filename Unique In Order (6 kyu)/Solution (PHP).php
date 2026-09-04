function uniqueInOrder(string | array $iterable): array {
    if ($iterable === "") {
        return [];
    }
    if (is_string($iterable)) {
        $iterable = str_split($iterable);
    }
    $result = [];
    foreach ($iterable as $element) {
        if (empty($result) || $element !== $result[count($result) - 1]) {
            $result[] = $element;
        }
    }
    return $result;
}