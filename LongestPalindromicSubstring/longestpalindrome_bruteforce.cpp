#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
public:
    int check_palindrome(string s, size_t&
        found, int start)
    {

        int palin_len = 0;
        int k = 0;
        for (int i = start; i <=found; i++)
        {
           
            if (s[i] != s[found - k])
                return -1;
            palin_len++;
            k++;

        }
        return palin_len;
    }
    string longestPalindrome(string s)
    {
        int cur_max = 0;
        string cur_string;
        for (int i = 0; i < s.length(); i++)
        {
            size_t found = s.find(s[i], i);
            int j = 1;
            while (found != string::npos)
            {
                int palindrome_len = check_palindrome(s, found,i);
                if (palindrome_len > cur_max)
                {
                    cur_max = palindrome_len;
                    cur_string = s.substr(i,palindrome_len);
                }
             
                found = s.find(s[i], found + j);
   
            }

        }
        return cur_string;

    }
};

