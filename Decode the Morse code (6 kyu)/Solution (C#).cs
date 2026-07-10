class MorseCodeDecoder {
    public static string Decode(string morseCode) {
        string result = "";
        string[] words = morseCode.Trim().Split("   ");
        for (int index_1 = 0; index_1 < words.Length; index_1++) {
            string[] letters = words[index_1].Split(" ");
            for (int index_2 = 0; index_2 < letters.Length; index_2++) {
                result += MorseCode.Get(letters[index_2]);
            }
            if (index_1 < words.Length - 1) {
                result += " ";
            }
        }
        return result;
    }
}