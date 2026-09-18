def stripComments(str: String, markers: Set[Char]): String = {
    return str.split("\n", -1).map(line => line.takeWhile(!markers.contains(_))
        .replaceAll("\\s+$", "")).mkString("\n")
}