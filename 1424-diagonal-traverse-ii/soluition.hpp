#include <vector>
#include <algorithm>
#include <tuple>

class Solution 
{
    public:
        
        /// @brief Given a list of lists of integers, nums, return all elements of nums in diagonal order as shown in the below images.
        /// @param nums List of lists of integers
        /// @return All elements of nums in diagonal order
        std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& nums) 
        {
            std::vector<int> res;
            std::vector<std::tuple<int, int, int>> elements;

            for (std::size_t i = 0; i < nums.size(); ++i)
            {
                for(std::size_t j = 0; j < nums[i].size(); ++j)
                    elements.emplace_back(i+j, j, nums[i][j]);
            }

            std::sort(elements.begin(), elements.end());

            for (const auto& element : elements)
                res.push_back(std::get<2>(element));

            return res;
        }
};