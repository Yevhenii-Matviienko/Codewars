digital_root <- function(n) {
    while (n >= 10) {
        sum_digits <- 0
        while (n > 0) {
            sum_digits <- sum_digits + n %% 10
            n <- n %/% 10
        }
        n <- sum_digits
    }
    return(n)
}