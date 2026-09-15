object PrimeDecomp {
    def factors(m: Int): String = {
        var number = m
        var divisor = 2
        val result = new StringBuilder
        while (divisor.toLong * divisor <= number) {
            var count_divisions = 0
            while (number % divisor == 0) {
                count_divisions += 1
                number /= divisor
            }
            if (count_divisions == 1) {
                result ++= s"($divisor)"
            } 
            else if (count_divisions > 1) {
                result ++= s"($divisor**$count_divisions)"
            }
            divisor += 1
        }
        if (number > 1) {
            result ++= s"($number)"
        }
        return result.toString
    }
}