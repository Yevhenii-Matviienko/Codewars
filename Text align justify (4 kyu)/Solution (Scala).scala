def justify(text: String, width: Int): String = {
    if (text.trim.isEmpty) {
        return ""
    }
    val words = text.trim.split("\\s+")
    val lines = scala.collection.mutable.ArrayBuffer[List[String]]()
    var line = List[String]()
    for (word <- words) {
        val line_with_word_length = (line :+ word).map(_.length).sum + line.size
        if (line.nonEmpty && line_with_word_length > width) {
            lines += line
            line = List(word)
        } 
        else {
            line = line :+ word
        }
    }
    lines += line
    val result = for ((line, line_index) <- lines.zipWithIndex) yield {
        if (line_index == lines.length - 1 || line.length == 1) {
            line.mkString(" ")
        } 
        else {
            val spaces = width - line.map(_.length).sum
            val gaps = line.length - 1
            var temporary_result = ""
            for (word_index <- line.indices) {
                temporary_result += line(word_index)
                if (word_index < gaps) {
                    val extra_gap = if (word_index < spaces % gaps) 1 else 0
                    temporary_result += " " * (spaces / gaps + extra_gap)
                }
            }
            temporary_result
        }
    }
    return result.mkString("\n")
}