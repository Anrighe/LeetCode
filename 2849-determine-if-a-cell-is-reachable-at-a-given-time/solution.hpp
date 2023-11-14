#include <cmath>

class Solution 
{
    public:
        /// @brief Checks if a cell is reachable in exactly t seconds
        /// @param sx Starting x coordinate
        /// @param sy Staring y coordinate
        /// @param fx Final x coordinate
        /// @param fy Final y coordinate
        /// @param t Number in which i want to reach the final cell
        /// @return true if the cell is reachable in exactly t seconds, false otherwise
        bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) 
        {
            if (sx == fx && sy == fy && t == 1)
                return false;

            if (t >= std::abs(fx-sx) && t >= std::abs(fy-sy))
                return true;
            else
                return false;
        }
};