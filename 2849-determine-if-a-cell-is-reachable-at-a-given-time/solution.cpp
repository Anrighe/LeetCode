#include <cmath>

class Solution 
{
    public:
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