array_diff <- function(a, b) {
    a[!a %in% b]
}