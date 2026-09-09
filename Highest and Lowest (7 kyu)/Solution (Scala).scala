object Sol {
    def highAndLow(numbers: String): String = {
        val numbers_array = numbers.split(" ").map(_.toInt)
        return s"${numbers_array.max} ${numbers_array.min}"
    }
}