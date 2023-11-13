#include <vector>
#include <algorithm>

class Solution 
{
    public:

        /// @brief Eliminates the maximum number of monsters from the game, where the game is played
        /// @param dist Vector of the distances of each monster from the city
        /// @param speed Vector of the speed of each monster in m/s
        /// @return The maximum number of monsters that can be eliminated
        int eliminateMaximum(std::vector<int>& dist, std::vector<int>& speed) 
        {
            int n = dist.size();
            std::vector <double> time_to_reach(n);

            for (std::size_t i = 0; i < n; ++i)
                time_to_reach[i] = (double)dist[i] / speed[i];

            std::sort(time_to_reach.begin(), time_to_reach.end());

            for (std::size_t eliminable_monsters = 0; eliminable_monsters < n; ++eliminable_monsters)
            {
                if (time_to_reach[eliminable_monsters] <= eliminable_monsters)
                    return eliminable_monsters;
            }
            return n;
        }
};