#include <iostream>
#include <string>
#include <algorithm> 

class Solution 
{
    public:
        std::string get_reverse_string(std::string s)
        {
            cout<<"The reverse of "<<s<<" is:";
            std::string reverse = "";
            for (std::size_t i = s.size() - 1; i >= 0; --i)
                reverse += s[i];
            
            cout<<reverse<<"\n";
            return reverse;
        }

        bool is_palindrome(std::string s)
        {
            
            if (get_reverse_string(s) == s)
                return true;
            else
                return false;
        }

        std::string form_string(char c1, char c2, char c3)
        {
            std::string str = "";
            return str + c1 + c2 + c3;
        }

        int countPalindromicSubsequence(std::string s) 
        {
            int palindrome_sub_count = 0;
            int s_size = s.size();

            std::string tmp = "";
            for (std::size_t index1 = 0; index1 < s_size; ++index1)
            {
                for (std::size_t index2 = 0; index2 < s_size; ++index2)
                {
                    for (std::size_t index3 = 0; index3 < s_size; ++index3)
                    {
                        if (index1 != index2 && index1 != index3 && index2 != index3)
                        {
                            cout<<s[index1]<<" "<<s[index2]<<" "<<s[index3]<<"\n";
                            cout<<form_string(s[index1], s[index2], s[index3])<<"\n";
                            tmp = "";
                            tmp = s[index1] + s[index2] + s[index3];
                            cout<<"TMP: "<<tmp<<"\n";
                            if (is_palindrome(form_string(s[index1], s[index2], s[index3])))
                                palindrome_sub_count++;
                        }
                    }
                }
            }
            return palindrome_sub_count;
        }
};

int main()
{
    Solution s;
    std::string str = "aabca";
    cout<<s.countPalindromicSubsequence(str)<<"\n";
    
    return 0;
}
