#include <algorithm>
#include <vector>
#include <cmath>

class Solution 
{
    public:

        /// @brief Return the sum of absolute differences between all pairs of nums
        /// @param nums Vector if integers
        /// @return Vector of integers with the sum of absolute differences
        std::vector<int> getSumAbsoluteDifferences(std::vector<int>& nums) 
        {
            int nums_size = nums.size();
            
            std::vector<int> res(nums_size, 0);

            std::vector<int> prefix(nums_size, 0);
            std::vector<int> suffix(nums_size, 0);

            prefix[0] = nums[0];
            for (int i = 1; i < nums_size; ++i) 
                prefix[i] = prefix[i - 1] + nums[i];

            suffix[nums_size - 1] = nums[nums_size - 1];
            for (int i = nums_size - 2; i >= 0; --i) 
                suffix[i] = suffix[i + 1] + nums[i];

            for (std::size_t i = 0; i < nums_size; ++i)
                res[i] = (nums[i] * i - prefix[i]) + (suffix[i] - nums[i] * (nums_size - i - 1));
                
            return res;
        }
};