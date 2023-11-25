#include <vector>
#include <algorithm>

class Solution 
{
    public:
        /**
         * Checks if the given subvector is an arithmetic sequence.
         *
         * @param subvector The vector to be checked.
         * @return True if the subvector is an arithmetic sequence, false otherwise.
         */
        bool is_arithmetic(std::vector<int> subvector)
        {   
            int subvector_size = subvector.size();
            
            int diff = subvector[1] - subvector[0];
            
            for (std::size_t i = 1; i < subvector_size; ++i)
            {
                if ((subvector[i] - subvector[i-1]) != diff)
                    return false;
            }
            return true;
        }

        /**
         * Checks if the subarrays of the given array satisfy the arithmetic sequence property.
         *
         * @param nums The input array of integers.
         * @param l The starting indices of the subarrays.
         * @param r The ending indices of the subarrays.
         * @return A vector of booleans indicating whether each subarray satisfies the arithmetic sequence property.
         */
        std::vector<bool> checkArithmeticSubarrays(std::vector<int>& nums, std::vector<int>& l, std::vector<int>& r) 
        {
            std::vector<bool> answer;

            for (std::size_t i = 0; i < l.size(); ++i)
            {
                std::vector<int> subvector = {nums.begin() + l[i], nums.begin() + r[i] +1}; 
                std::sort(subvector.begin(), subvector.end());

                if(is_arithmetic(subvector))
                    answer.push_back(true);
                else
                    answer.push_back(false);
                
            }
            return answer;
        }   
};