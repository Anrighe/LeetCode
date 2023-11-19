#include <vector>
#include <map>

class Solution 
{
    public:
        /// @brief Finds the minimum number of operations to make all elements in nums equal, 
        ///         where only reductions on the current maximum element in the array are permitted. 
        /// @param nums Vector of integers
        /// @return The integer corresponding to the minimum number of operations
        int reductionOperations(std::vector<int>& nums)
        {
            std::map<int, int> occurrences;

            int operations = 0;
            int elements = 0;

            for (std::size_t i = 0; i < nums.size(); ++i)
            {
                if (occurrences.count(nums[i]))
                    occurrences[nums[i]] += 1;
                else
                    occurrences.insert({nums[i], 1});
            }

            for (auto i = occurrences.rbegin(); i != occurrences.rend(); ++i) 
            {
                if (i->first != occurrences.begin()->first)
                {
                    elements += i->second;
                    operations = operations + elements;
                }    
            }

            return operations;
        }
};