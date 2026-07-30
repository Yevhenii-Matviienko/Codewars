solution <- function(s) {
    if (s == "") {
        return(c())
    }
    if (nchar(s) %% 2 == 1) {
        s <- paste0(s, "_")
    }
    symbols_pairs_starts <- seq(1, nchar(s), by = 2)
    substring(s, symbols_pairs_starts, symbols_pairs_starts + 1)
}