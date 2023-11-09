#include <vector>

class Solution 
{
    public:
    
        int max_element(std::vector<int>& arr)
        {
            int max = 0;
            for (std::size_t i = 0; i < arr.size(); ++i)
            {
                if (max < arr[i])
                    max = arr[i];
            }
            return max;
        }

        int getWinner(std::vector<int>& arr, int k) 
        {
            int consecutive_wins = 0;
            int max = arr[0];

            if (k >= arr.size())
                return max_element(arr);
            else
            {
                for (std::size_t i = 0; i < arr.size(); ++i)
                {
                    if (consecutive_wins >= k)
                        return max;

                    if (arr[i] > max)
                    {
                        max = arr[i];
                        consecutive_wins = 1;
                    }
                    else
                    {
                        if (max > arr[i])
                            consecutive_wins++;
                    }
                }
            }

            return max;
        }
};