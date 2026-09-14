object Kata {
    def narcissistic(n: Int): Boolean = {
        val digits = n.toString
        val power = digits.length
        val sum = digits.map(digit => math.pow(digit - '0', power)).sum
        return sum == n
    }
}