high_and_low <- function(numbers) {
    numbers_double <- as.numeric(strsplit(numbers, " ")[[1]])
    paste(max(numbers_double), min(numbers_double))
}