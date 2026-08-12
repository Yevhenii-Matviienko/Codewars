public class Kata {
    public static String incrementString(String str) {
        int index = str.length() - 1;
        while (index >= 0 && Character.isDigit(str.charAt(index))) {
            index--;
        }
        if (index == str.length() - 1) {
            return str + "1";
        }
        String text = str.substring(0, index + 1);
        StringBuilder number = new StringBuilder(str.substring(index + 1));
        int carry = 1;
        for (index = number.length() - 1; index >= 0 && carry == 1; index--) {
            if (number.charAt(index) == '9') {
                number.setCharAt(index, '0');
            } 
            else {
                number.setCharAt(index, (char) (number.charAt(index) + 1));
                carry = 0;
            }
        }
        if (carry == 1) {
            number.insert(0, '1');
        }
        return text + number;
    }
}