#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isPalindrome(string & s, const int &start, const int &end)
    {
        int k = 0;
        for (int i = start; i <=end; i++)
        {
            if (s[i] != s[end - k])
                return false;
            k++;

        }
        return true;
    }
    string longestPalindrome(string s)
    {
        if(s.size()<=1) return s;
        int cur_max = 1;
        string cur_string="";
        cur_string+=s[0]; //as single word is palindrome
        for (int i = 0; i < s.length(); i++)
        {
            for(int j=i+1; j<s.length(); j++)
            {
                if(isPalindrome(s,i,j))
                {
                    if(cur_max<j-i+1) //check if curmax exceeds.
                    {
                        cur_max=j-i+1;
                        cur_string=s.substr(i,j-i+1);
                    }

                }
            }

        }
        return cur_string;

    }
};

