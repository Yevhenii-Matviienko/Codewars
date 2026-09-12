import Preloaded.Direction
import Direction._
import scala.collection.mutable.ArrayBuffer

def dirReduc(xs: Seq[Direction]): Seq[Direction] = {
    val opposite_directions = Map(
        North -> South,
        South -> North,
        East -> West,
        West -> East
    )
    val result = ArrayBuffer.empty[Direction]
    for (direction <- xs) {
        if (result.nonEmpty && opposite_directions(direction) == result.last) {
            result.remove(result.length - 1)
        } 
        else {
            result.append(direction)
        }
    }
    result.toSeq
}