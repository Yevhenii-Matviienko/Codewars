def pyramidHeight(n: Int): Int = {
    var pyramid_height = 0
    var remaining_cubes = n
    while (remaining_cubes >= (pyramid_height + 1) * (pyramid_height + 1)) {
        pyramid_height += 1
        remaining_cubes -= pyramid_height * pyramid_height
    }
    return pyramid_height
}