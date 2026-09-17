def solution(xs: List[Int]): String = {
    val numbers_array = xs.toArray
    var index = 0
    val result = scala.collection.mutable.ListBuffer[String]()
    while (index < numbers_array.length) {
        val range_start = index
        while (index + 1 < numbers_array.length && numbers_array(index + 1) == numbers_array(index) + 1) {
            index += 1
        }
        if (index - range_start >= 2) {
            result += s"${numbers_array(range_start)}-${numbers_array(index)}"
        } 
        else if (index - range_start == 1) {
            result += numbers_array(range_start).toString
            result += numbers_array(index).toString
        } 
        else {
            result += numbers_array(range_start).toString
        }
        index += 1
    }
    return result.mkString(",")
}