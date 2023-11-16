#include <string>
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

class Solution 
{
    public:

        /// @brief Finds an occurrence of a binary string that is not in the given vector of binary strings.
        /// @param nums Vector of binary strings.
        /// @return The binary string that is not in the given vector of binary strings.
        std::string findDifferentBinaryString(std::vector<std::string>& nums) 
        {
            const int n = nums.size();
            
            unsigned long long value;
            std::vector<int> integers;

            std::string missing;

            for (std::size_t i = 0; i < n; ++i)
            {
                value = std::bitset<64>(nums[i]).to_ullong();
                integers.push_back(value);
            }

            std::sort(integers.begin(), integers.end());

            for (std::size_t i = 0; i < n; ++i)
            {
                if (integers[i] != i)
                {
                    int n = nums.size();
                    missing = std::bitset<16>(i).to_string();

                    return missing.substr(missing.length()-n, missing.length());
                }
            }

            missing = std::bitset<16>(n).to_string();
            return missing.substr(missing.length()-n, missing.length());
        }
};