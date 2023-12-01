class Solution 
{
    /**
     * Checks if two string arrays are equivalent by concatenating all the strings in each array and comparing the resulting strings.
     * 
     * @param word1 the first string array
     * @param word2 the second string array
     * @return true if the concatenated strings are equal, false otherwise
     */
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) 
    {   
        String res1 = "";
        String res2 = "";

        if (word1.length == word2.length)
        {
            for (int i = 0; i < word1.length; ++i)
            {
                res1 += word1[i];
                res2 += word2[i];
            }
        }
        else
        {
            for (int i = 0; i < word1.length; ++i)
                res1 += word1[i];

            for (int i = 0; i < word2.length; ++i)
                res2 += word2[i];
        }

        if (res1.equals(res2))
            return true;
        else
            return false;
    }
}