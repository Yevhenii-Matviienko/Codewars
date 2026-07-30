duplicate_encode <- function(word) {
    word <- tolower(word)
    symbols <- strsplit(word, "")[[1]]
    symbols_counts <- table(symbols)
    paste0(ifelse(symbols_counts[symbols] > 1, ")", "("), collapse = "")
}