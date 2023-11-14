#include <iostream>
#include <string>
#include <algorithm> 
#include <unordered_set>
#include <vector>

#define ALPHABET_LETTERS_COUNT 26

class Solution 
{
    public:

        /// @brief Counts the number of unique palindromic subsequences of length 3
        /// @param s String to be analyzed
        int countPalindromicSubsequence(std::string s) 
        {
            int s_size = s.size();
            std::vector<int> first_occurrence(26, -1);  
            std::vector<int> last_occurrence(26, -1);

            std::unordered_set <std::string> palindrome_set;

            for (std::size_t i = 0; i < s_size; ++i)
            {
                if (first_occurrence[s[i] - 'a'] == -1)
                    first_occurrence[s[i] - 'a'] = i;

                last_occurrence[s[i] - 'a'] = i;
            }

            for (size_t i = 0; i < ALPHABET_LETTERS_COUNT; ++i)
            {
                if ((first_occurrence[i] + 1) < last_occurrence[i])
                {
                    for(std::size_t j = first_occurrence[i]+1; j < s_size; ++j)
                    {
                        if (j < last_occurrence[i])
                            palindrome_set.insert(std::string({s[first_occurrence[i]], s[j], s[last_occurrence[i]]}));
                    }
                }
            }

            return palindrome_set.size();
        }
};


