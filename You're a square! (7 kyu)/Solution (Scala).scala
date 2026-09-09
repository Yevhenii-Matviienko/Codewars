object Sol {
    def isSquare(x: Int): Boolean = {
        if (x < 0) {
            return false
        } 
        else {
            val square_root = Math.sqrt(x).toInt
            return square_root * square_root == x
        }
    }
}