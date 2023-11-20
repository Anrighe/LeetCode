#include <vector>
#include <string>

class Solution 
{
    public:
        /// @brief Calculates the time (minutes) needed for the trucks to collect all the garbage in each house
        /// @param garbage Vector of strings representing the garbage in each house
        /// @param travel Vector of integers representing the time (minutes) needed to go from house i to house i + 1
        /// @return The minutes needed to collect all the garbage in each house
        int garbageCollection(std::vector<std::string>& garbage, std::vector<int>& travel) 
        {
            int time = 0;

            int furthest_paper = -1;
            int furthest_glass = -1;
            int furthest_metal = -1;

            for (int i = garbage.size()-1; i >= 0; --i)
            {
                for (std::size_t j = 0; j < garbage[i].length(); ++j)
                {
                    if (garbage[i][j] == 'P' && furthest_paper == -1)
                        furthest_paper = i;

                    if (garbage[i][j] == 'G' && furthest_glass == -1)
                        furthest_glass = i;                   

                    if (garbage[i][j] == 'M' && furthest_metal == -1)
                        furthest_metal = i; 

                    if (furthest_paper != -1 && furthest_glass != -1 && furthest_metal != -1)
                        break;
                }
                
                if (furthest_paper != -1 && furthest_glass != -1 && furthest_metal != -1)
                    break;
            }

            for (std::size_t i = 0; i < garbage.size(); ++i)
                time += garbage[i].length();

            for (int i = 0; i < furthest_paper; ++i)
                time += travel[i];

            for (int i = 0; i < furthest_glass; ++i)
                time += travel[i];

            for (int i = 0; i < furthest_metal; ++i)
                time += travel[i];

            return time;
        }         
};