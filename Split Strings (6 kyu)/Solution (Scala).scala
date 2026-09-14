object Kata {
    def solution(s: String): List[String] = {
        val text = if (s.length % 2 != 0) s + "_" else s
        return text.grouped(2).toList
    }
}