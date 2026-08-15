import kotlin.math.pow

fun digPow(n: Int, p: Int): Int {
    var sum = 0
    var power = p
    for (digit in n.toString()) {
        sum += digit.digitToInt().toDouble().pow(power).toInt()
        power++
    }
    return if (sum % n == 0) (sum / n).toInt() else -1
}