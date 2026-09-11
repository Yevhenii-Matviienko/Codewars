import scala.collection.mutable.ListBuffer

object Kata {
    def uniqueInOrder[T](xs: Iterable[T]): Seq[T] = {
        val result = ListBuffer.empty[T]
        for (element <- xs) {
            if (result.isEmpty || result.last != element) {
                result += element
            }
        }
        return result.toSeq
    }
}