import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {

    /**
     * Calculates the number of occurrences of a specific character in a given word.
     *
     * @param charToCheck The character to count.
     * @param word The word in which to count the character.
     * @return The number of occurrences of charToCheck in word.
     */
    public int calculateOccurrencies(char charToCheck, String word) {
        int occurrencies = 0;
        for (int i = 0; i < word.length(); ++i) {
            if (charToCheck == word.charAt(i))
                occurrencies += 1;
        }
        return occurrencies;
    }

    /**
     * Finds the common characters in an array of strings (with duplicates).
     *
     * @param words The array of strings to find common characters from.
     * @return A list of common characters.
     */
    public List<String> commonChars(String[] words) {
        if (words.length == 0)
            return new ArrayList<>();

        List<String> result = new ArrayList<>();

        if (words.length == 1) {
            for (int i = 0; i < words[0].length(); ++i)
                result.add("" + words[0].charAt(i));
            return result;
        }

        Map<String, Integer> charactersMap = new HashMap<>();
        String currentCharAsString;

        // Adding all letters of the first word to the Map with their frequencies
        for (int i = 0; i < words[0].length(); ++i) {
            currentCharAsString = "" + words[0].charAt(i);
            if (!charactersMap.containsKey(currentCharAsString)) {
                charactersMap.put(currentCharAsString, 1);
            } else {
                charactersMap.put(currentCharAsString, charactersMap.get(currentCharAsString) + 1);
            }
        }
        
        // Updating the frequencies in the map based on other words
        int occurrencies;
        for (Map.Entry<String, Integer> entry : charactersMap.entrySet()) {
            for (int i = 1; i < words.length; ++i) {
                occurrencies = calculateOccurrencies(entry.getKey().charAt(0), words[i]);
                if (occurrencies < entry.getValue())
                    charactersMap.put(entry.getKey(), occurrencies);
            }
        }

        // Adding the common characters to the result list based on their frequencies
        for (Map.Entry<String, Integer> entry : charactersMap.entrySet()) {
            for (int i = 0; i < entry.getValue(); ++i)
                result.add(entry.getKey());
        }

        return result;
    }
}
