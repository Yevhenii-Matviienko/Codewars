public class MorseCodeDecoder {
    public static String decode(String morseCode) {
        String morse_code = morseCode.trim();
        if (morse_code.isEmpty()) {
            return "";
        }
        String[] words = morse_code.split("   ");
        StringBuilder result = new StringBuilder();
        for (int index = 0; index < words.length; index++) {
            String[] letters = words[index].split(" ");
            for (String letter : letters) {
                result.append(MorseCode.get(letter));
            }
            if (index < words.length - 1) {
                result.append(" ");
            }
        }
        return result.toString();
    }
}