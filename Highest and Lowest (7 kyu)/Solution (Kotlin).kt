fun highAndLow(numbers: String): String {
    val numbers_array = numbers.split(" ").map { number -> number.toInt() }
    return "${numbers_array.maxOrNull()} ${numbers_array.minOrNull()}"
}