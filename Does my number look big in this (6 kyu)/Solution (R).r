armstrong <- function(num) {
    sum <- 0
    digits <- strsplit(as.character(num), "")[[1]]
    for (digit in digits) {
        sum <- sum + as.numeric(digit) ^ length(digits)
    }
    sum == num
}