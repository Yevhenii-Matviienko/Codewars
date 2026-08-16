package morsecode

fun decodeMorse(code: String): String {
    return code.trim().split("   ").joinToString(" ") { 
        word -> word.split(" ").joinToString("") { 
            letter -> MorseCode[letter] ?: ""
        }
    }
}