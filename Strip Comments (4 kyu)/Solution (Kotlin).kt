fun solution(input: String, markers: CharArray): String {
    return input.lines().joinToString("\n") { 
        line -> line.takeWhile { 
            symbol -> symbol !in markers 
        }.trimEnd()
    }
}