object Solution {
    def isValidWalk(walk: Seq[Char]): Boolean = {
        return walk.length == 10 &&
            walk.count(_ == 'n') == walk.count(_ == 's') &&
            walk.count(_ == 'e') == walk.count(_ == 'w')
    }
}