#include <vector>
#include <algorithm>

class Solution 
{
    public:

        /// @brief Finds the minimum maximum pair sum in the array
        /// @param nums The array of integers
        /// @return The minimum maximum pair sum
        int minPairSum(std::vector<int>& nums) 
        {
            int maximum_pair_sum = 0;
            int current_pair_sum;

            int ptr1 = 0;
            int ptr2 = nums.size() - 1;

            std::sort(nums.begin(), nums.end());

            while (ptr1 < ptr2)
            {

                current_pair_sum = nums[ptr1] + nums[ptr2];
                if (current_pair_sum > maximum_pair_sum)
                    maximum_pair_sum = current_pair_sum;

                ptr1++;
                ptr2--;
            }

            return maximum_pair_sum;
        }
};