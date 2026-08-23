function dirReduc($arr) {
    $opposite_directions = [
        "NORTH" => "SOUTH",
        "SOUTH" => "NORTH",
        "EAST" => "WEST",
        "WEST" => "EAST"
    ];
    $result = [];
    foreach ($arr as $direction) {
        if (!empty($result) && $opposite_directions[$direction] === end($result)) {
            array_pop($result);
        } 
        else {
            $result[] = $direction;
        }
    }
    return $result;
}