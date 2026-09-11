object Kata {
    def count(string: String): Map[Char, Int] = {
        return string.groupBy(identity).view.mapValues(_.length).toMap
    }
}
