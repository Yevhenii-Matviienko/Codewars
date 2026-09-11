object Kata {
    def arrayDiff(a: Seq[Int], b: Seq[Int]): Seq[Int] = {
        a.filterNot(b.toSet.contains)
    }
}