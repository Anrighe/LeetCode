import java.util.HashMap;

class Solution 
{
    /**
     * Counts the total number of characters in the given array of words that can be formed using the characters in the given string.
     * 
     * @param words an array of strings representing the words
     * @param chars a string representing the available characters
     * @return the total number of characters that can be formed
     */
    public int countCharacters(String[] words, String chars) 
    {
        int res = 0;
        HashMap<Character, Integer> letterCount = new HashMap<Character, Integer>();
        boolean suitable = true;

        for (int i = 0; i < chars.length(); ++i)
        {
            if (letterCount.containsKey(chars.charAt(i)))
                letterCount.put(chars.charAt(i), letterCount.get(chars.charAt(i)) + 1);
            else
                letterCount.put(chars.charAt(i), 1);
        }

        for (String str : words)
        {
            suitable = true;
            HashMap<Character, Integer> letterCountCopy = new HashMap<>(letterCount);

            for (int i = 0; i < str.length(); ++i)
            {
                char currentChar = str.charAt(i);
                
                if (!letterCountCopy.containsKey(currentChar) || letterCountCopy.get(currentChar) <= 0)
                {
                    suitable = false;
                    break;
                }
                letterCountCopy.put(currentChar, letterCountCopy.get(currentChar) - 1);
            }
            if (suitable == true)
                res += str.length();
        }
        return res;
    }
}