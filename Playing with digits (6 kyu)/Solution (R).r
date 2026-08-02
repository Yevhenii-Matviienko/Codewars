digPow <- function(n, p) {
    digits <- strsplit(as.character(n), "")[[1]]
    sum <- 0
    for (digit in digits) {
        sum <- sum + as.numeric(digit) ^ p
        p <- p + 1
    }
    if (sum %% n == 0) {
        return(sum / n)
    }
    return(-1)
}