#include <vector>

class Solution 
{
    public:
    
        /// @brief Finds the maximum element in the vector
        /// @param arr Vector to search
        /// @return The maximum element in the vector
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

        /// @brief Finds the winner of the game, where the game is played between the first two 
        ///     elements of the array and the winner is the larger of the two. The winner then
        ///     plays against the next element in the array and so on. The game ends when one
        ///     element has won k consecutive games.
        /// @param arr Vector of integers
        /// @param k Number of consecutive wins required to win the game
        /// @return An integer representing the winner of the game
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