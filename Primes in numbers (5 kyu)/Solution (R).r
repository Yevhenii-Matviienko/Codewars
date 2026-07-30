primeFactors <- function(n) {
    result <- c()
    divisor <- 2
    while (n > 1) {
        count_divisions <- 0
        while (n %% divisor == 0) {
            n <- n %/% divisor
            count_divisions <- count_divisions + 1
        }
        if (count_divisions == 1) {
            result <- c(result, paste0("(", divisor, ")"))
        }
        if (count_divisions > 1) {
            result <- c(result, paste0("(", divisor, "**", count_divisions, ")"))
        }
        divisor <- divisor + 1
    }
    paste0(result, collapse = "")
}