fun find(integers: Array<Int>): Int {
    val even_numbers = integers.filter { number -> number % 2 == 0 }
    val odd_numbers = integers.filter { number -> number % 2 != 0 }
    return if (even_numbers.size == 1) {
        even_numbers[0]
    } 
    else {
        odd_numbers[0]
    }
}
