object SumOfDigits {
    def digitalRoot(n: Int): Int = {
        return if (n == 0) 0 else if (n % 9 == 0) 9 else n % 9
    }
}