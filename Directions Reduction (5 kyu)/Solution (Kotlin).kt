package solution

object DirReduction {
    fun dirReduc(arr: Array<String>): Array<String> {
        val opposite_directions = mapOf(
            "NORTH" to "SOUTH",
            "SOUTH" to "NORTH",
            "EAST" to "WEST",
            "WEST" to "EAST"
        )
        val result = mutableListOf<String>()
        for (direction in arr) {
            if (result.isNotEmpty() && opposite_directions[direction] == result.last()) {
                result.removeAt(result.lastIndex)
            } 
            else {
                result.add(direction)
            }
        }
        return result.toTypedArray()
    }
}