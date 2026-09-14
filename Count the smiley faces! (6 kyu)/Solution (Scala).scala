object Kata {
    def countSmileys(vec: Vector[String]): Int = {
        val pattern = "^[:;][-~]?[)D]$".r
        return vec.count(smiley => pattern.matches(smiley))
    }
}