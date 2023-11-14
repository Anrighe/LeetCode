#include <iostream>
#include <string>
#include <algorithm> 
#include <unordered_set>
#include <vector>
#include "solution.hpp"

int main()
{
    Solution s;
    std::string str = "bbcbaba";

    std::cout<<s.countPalindromicSubsequence(str)<<"\n";
    
    return 0;
}