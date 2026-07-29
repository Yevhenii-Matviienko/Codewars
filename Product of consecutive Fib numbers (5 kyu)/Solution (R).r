productFib <- function(prod) {
    number_1 <- 0
    number_2 <- 1
    while (number_1 * number_2 < prod) {
        number_3 <- number_1 + number_2
        number_1 <- number_2
        number_2 <- number_3
    }
    c(number_1, number_2, number_1 * number_2 == prod)
}