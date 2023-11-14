#include <string>
#include <vector>
#include <algorithm>

class Solution 
{
    public:

        /// @brief Checks if a character is a vowel
        /// @param value The ascii value of the character
        /// @return true if value is a vowel, false otherwise
        bool is_vowel(int value)
        {
            if (value <= 90)
            {
                if (value == 65 || value == 69 || value == 73 || value == 79 || value == 85)
                    return true;
            }
            else
            {
                if (value == 97 || value == 101 || value == 105 || value == 111 || value == 117)
                    return true;
            }

            return false;
        }

        /// @brief Sorts the vowels in a string based on their ascii value in non-decreasing order and 
        ///     places them in the same positions in the string where other vowels were
        /// @param s String to sort
        /// @return The sorted string
        std::string sortVowels(std::string s) 
        {
            std::vector<char> vowels;
            std::vector<int> vowel_positions;
            for (std::size_t i = 0; i < s.size(); ++i)
            {
                if (is_vowel(static_cast <int>(s[i])))
                {
                    vowels.push_back(s[i]);
                    vowel_positions.push_back(i);
                }
            }
            
            std::sort(vowels.begin(), vowels.end());

            for (std::size_t i = 0; i < vowels.size(); ++i)
                s[vowel_positions[i]] = vowels[i];

            return s;
        }
};