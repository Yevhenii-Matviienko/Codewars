object Parity {
    def findOutlier(integers: List[Int]): Int = {
        val even_numbers = integers.filter(_ % 2 == 0)
        val odd_numbers = integers.filter(_ % 2 != 0)
        if (even_numbers.length == 1) {
            return even_numbers.head 
        }
        else {
            return odd_numbers.head
        }
    }
}