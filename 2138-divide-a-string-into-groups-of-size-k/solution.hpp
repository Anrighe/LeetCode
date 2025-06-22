#include <string>
#include <vector>

class Solution {
    public:

        /**
         * Fills a string with a specified character until it reaches the desired length
         * @param group The input string to be filled
         * @param desiredLength The target length of the string after filling
         * @param fill The character used to fill the string
         * @return std::string The filled string with the specified length
         */
        std::string fillGroup(std::string group, int desiredLength, char fill) {
            int fillToInsert = desiredLength - group.length();
            for (std::size_t index = 0; index < fillToInsert; ++index) {
                group += fill;
            }
            return group;
        }
    
        /**
         * Divides a string into groups of size k, filling the last group with a specified character if necessary
         * @param s The input string to be divided into groups
         * @param k The size of each group
         * @param fill The character used to fill the last group if its size is less than k
         * @return A vector containing the groups of size k
         */
        std::vector<std::string> divideString(std::string s, int k, char fill) {
            std::vector<std::string> groups;
            std::string group = "";
            for (std::size_t index = 0; index < s.length(); ++index) {
                if (group.length() < k) {
                    group += s[index];
    
                    if (group.length() == k) {
                        groups.push_back(group);
                        group = "";
                    }
                }
            }
    
            if (group != "" && group.length() > 0) {
                groups.push_back(fillGroup(group, k, fill));
            }
            return groups;
        }
    };