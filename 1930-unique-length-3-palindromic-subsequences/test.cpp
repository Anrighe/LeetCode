#include <iostream>
#include "solution.hpp"

int main()
{
    Solution s;
    std::string str = "bbcbaba";

    std::cout<<s.countPalindromicSubsequence(str)<<"\n";
    
    return 0;
}