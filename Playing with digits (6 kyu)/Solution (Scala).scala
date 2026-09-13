object DigPow {
    def digPow(n: Int, p: Int): Int = {
        var power = p
        var sum = 0L
        for (digit <- n.toString) {
            sum += math.pow(digit - '0', power).toLong
            power += 1
        }
        if (sum % n == 0) {
            return (sum / n).toInt
        }
        else {
            return -1
        }
    }
}