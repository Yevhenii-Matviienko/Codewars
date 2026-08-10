public class DirReduction {
    public static String[] dirReduc(String[] arr) {
        String[] result = new String[arr.length];
        int amount_directions = 0;
        for (String direction : arr) {
            if (amount_directions > 0 &&
                ((result[amount_directions - 1].equals("NORTH") && direction.equals("SOUTH")) ||
                (result[amount_directions - 1].equals("SOUTH") && direction.equals("NORTH")) ||
                (result[amount_directions - 1].equals("EAST") && direction.equals("WEST")) ||
                (result[amount_directions - 1].equals("WEST") && direction.equals("EAST")))) {
                amount_directions--;
            } 
            else {
                result[amount_directions] = direction;
                amount_directions++;
            }
        }
        String[] answer = new String[amount_directions];
        for (int index = 0; index < amount_directions; index++) {
            answer[index] = result[index];
        }
        return answer;
    }
}