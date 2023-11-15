#include <string>

class Solution 
{
    public:

        /**
         * @brief Reverses the order of words in a given string.
         * 
         * @param s The string to reverse.
         * @return The reversed string.
         */
        std::string reverseWords(std::string s)
        {  
            int s_size = s.size();
            int start = 0;
            std::string reversed = "";

            for(std::size_t i = 0; i <= s_size; ++i)
            {
                if (s[start] == ' ')
                    start = i;
                else
                {
                    if ((i > start && s[i] == ' ' ) || (i > start && i == s_size))
                    {
                        reversed = s.substr(start, i-start) + " " + reversed;
                        start = i;  
                    }
                }
            }

            while(reversed[reversed.length()-1] == ' ')
                reversed = reversed.substr(0, reversed.length()-1);

            return reversed;
        }
};