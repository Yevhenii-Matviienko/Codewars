solution <- function(roman) {
    roman_decimal_numbers <- c(
        I = 1,
        V = 5,
        X = 10,
        L = 50,
        C = 100,
        D = 500,
        M = 1000
    )
    roman_number_symbols <- strsplit(roman, "")[[1]]
    result <- 0
    for (index in seq_along(roman_number_symbols)) {
        current_decimal_digit <- roman_decimal_numbers[roman_number_symbols[index]]
        next_decimal_digit <- ifelse(index < length(roman_number_symbols), roman_decimal_numbers[roman_number_symbols[index + 1]], 0)
        if (current_decimal_digit < next_decimal_digit) {
            result <- result - current_decimal_digit
        } 
        else {
            result <- result + current_decimal_digit
        }
    }
    as.numeric(result)
}