#include <vector>
#include <algorithm>

class Solution 
{
    public:
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