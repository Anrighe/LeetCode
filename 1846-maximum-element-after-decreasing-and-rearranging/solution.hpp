#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_VALUE 1000000000
#define MIN_VALUE 1

class Solution 
{
    public:

        int maximumElementAfterDecrementingAndRearranging(std::vector<int>& arr) 
        {
            int max = MIN_VALUE;
            
            std::sort(arr.begin(), arr.end());

            if (arr[0] != 1)
                arr[0] = 1;

            for (std::size_t i = 1; i < arr.size(); ++i)
            {
                if (arr[i-1]+1 == arr[i])
                    max = arr[i];
                else
                {
                    if (arr[i] > arr[i-1])
                    {
                        arr[i] = arr[i-1] + 1;
                        max = arr[i]; 
                    }
                }
            }
            
            return max;
        }
};