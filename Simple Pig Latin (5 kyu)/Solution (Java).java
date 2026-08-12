public class PigLatin {
    public static String pigIt(String str) {
        String[] words = str.split(" ");
        String result = "";
        for (String word : words) {
            if (Character.isLetter(word.charAt(0))) {
                result += word.substring(1) + word.charAt(0) + "ay";
            } 
            else {
                result += word;
            }
            result += " ";
        }
        return result.trim();
    }
}