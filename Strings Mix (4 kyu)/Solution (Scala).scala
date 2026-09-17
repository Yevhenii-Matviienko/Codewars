object StringMix {
    def mix(s1: String, s2: String): String = {
        val result_parts = for {
            letter <- 'a' to 'z'
            count_letter_1 = s1.count(_ == letter)
            count_letter_2  = s2.count(_ == letter)
            max_count_letter = count_letter_1 max count_letter_2
            if max_count_letter > 1
        } yield s"${
            if (count_letter_1 > count_letter_2) "1" 
            else if (count_letter_2 > count_letter_1) "2" 
            else "="
        }:${
            letter.toString * max_count_letter
        }"
        return result_parts.sortBy(result_part => (-result_part.length, result_part)).mkString("/")
    }
}