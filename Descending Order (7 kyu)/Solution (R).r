descending_order <- function(num) {
    as.numeric(paste0(sort(strsplit(as.character(num), "")[[1]], decreasing = TRUE), collapse = ""))
}