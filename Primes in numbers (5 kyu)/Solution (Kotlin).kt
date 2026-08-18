package solution

object PrimeDecomp {
    fun factors(l: Int): String {
        var number = l
        var divisor = 2
        var result = ""
        while (divisor <= number / divisor) {
            var count_divisions = 0
            while (number % divisor == 0) {
                count_divisions++
                number /= divisor
            }
            if (count_divisions == 1) {
                result += "($divisor)"
            } 
            else if (count_divisions > 1) {
                result += "($divisor**$count_divisions)"
            }
            divisor++
        }
        if (number > 1) {
            result += "($number)"
        }
        return result
    }
}