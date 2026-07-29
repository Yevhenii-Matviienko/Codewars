dirReduc <- function(arr) {
    opposites_directions <- c(
        "NORTH" = "SOUTH",
        "SOUTH" = "NORTH",
        "EAST" = "WEST",
        "WEST" = "EAST"
    )
    result <- c()
    for (direction in arr) {
        if (length(result) > 0 && opposites_directions[[direction]] == result[length(result)]) {
            result <- result[-length(result)]
        } 
        else {
            result <- c(result, direction)
        }
    }
    result
}