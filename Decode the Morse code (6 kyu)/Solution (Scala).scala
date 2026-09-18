import MorseCodes.morseCodes

object MorseDecoder {
    def decode(msg: String): String = {
        return msg.trim.split("   ").map(_.split(" ").map(morseCodes).mkString).mkString(" ")
    }
}