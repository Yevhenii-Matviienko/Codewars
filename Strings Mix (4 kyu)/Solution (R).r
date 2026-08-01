mix <- function(s1, s2) {
    count_chars_string_1 <- table(strsplit(s1, "")[[1]])
    count_chars_string_2 <- table(strsplit(s2, "")[[1]])
    result_parts <- sapply(letters, function(letter) {
        number_char_string_1 <- ifelse(letter %in% names(count_chars_string_1), count_chars_string_1[letter], 0)
        number_char_string_2 <- ifelse(letter %in% names(count_chars_string_2), count_chars_string_2[letter], 0)
        max_number_char <- max(number_char_string_1, number_char_string_2)
        if (max_number_char <= 1) { 
            return("")
        }
        result_part <- if (number_char_string_1 > number_char_string_2) "1:" else if (number_char_string_2 > number_char_string_1) "2:" else "E:"
        paste0(result_part, strrep(letter, max_number_char))
    })
    result_parts <- result_parts[result_parts != ""]
    return(paste(result_parts[order(-nchar(result_parts), result_parts)], collapse = "/"))
}