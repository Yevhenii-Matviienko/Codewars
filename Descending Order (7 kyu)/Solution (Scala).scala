object Order {
    def descendingOrder(num: Int): Int = {
        return num.toString.sorted.reverse.toInt
    }
}