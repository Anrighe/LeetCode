#include <vector>
#include <algorithm>

class Solution 
{
    public:

        /// @brief Finds the maximum frequency of an element in the array given up to k possible increments of 
        ///     any element in the array by 1
        /// @param nums Vector of integers
        /// @param k The maximum number of increments of any element in the array by 1
        /// @return The integer corresponding to the maximum frequency
        int maxFrequency(std::vector<int>& nums, int k) 
        {
            std::sort(nums.begin(), nums.end());

            int nums_size = nums.size();
            int max_freq = 1;
            long int total_sum = nums[0];
            long int left = 0;

            for (long int right = 1; right < nums_size; ++right) 
            {
                total_sum += nums[right];

                // While the target value is greater than the actual value + k, the left side of the window gets shrinked
                while (nums[right] * (right - left + 1) > total_sum + k) 
                {
                    total_sum -= nums[left];
                    ++left;
                }

                max_freq = std::max<int>(max_freq, (right - left + 1));
            }

            return max_freq;
        }
};