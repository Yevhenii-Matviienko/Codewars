isValidWalk <- function(walk) {
    return(length(walk) == 10 &&
        sum(walk == "n") == sum(walk == "s") &&
        sum(walk == "e") == sum(walk == "w"))
}