package prodfib

fun productFib(prod: Long): LongArray {
    var number_1 = 0L
    var number_2 = 1L
    while (number_1 * number_2 < prod) {
        val number_3 = number_1 + number_2
        number_1 = number_2
        number_2 = number_3
    }
    return longArrayOf(number_1, number_2, if (number_1 * number_2 == prod) 1L else 0L)
}