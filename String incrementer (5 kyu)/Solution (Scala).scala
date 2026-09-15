def incrementString(s: String): String = {
    val number = "\\d*$".r.findFirstIn(s).getOrElse("")
    val text = if (number.nonEmpty) s.dropRight(number.length) else s
    val incremented_number = ((if (number.isEmpty) "0" else number).toLong + 1).toString
    return text + incremented_number.reverse.padTo(number.length, '0').reverse
}