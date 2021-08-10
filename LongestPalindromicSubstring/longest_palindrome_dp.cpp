#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<map>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s)
    {
        if (s.size() == 0) return "";
        vector<vector<bool> > pand(s.size(), vector<bool>(s.size(), false)); //initialization
        string cur_string = "";
        cur_string += s[0];//smallest cse.
        for (int i = 0; i < s.size(); i++)
        {
            pand[i][i] = true; //single word is palindrome
        }
        int cur_max = 1;
        for (int l = 1; l <= s.size(); l++)
        {
            //l refer to the lenght that we are going to check.. i.e l=1 means that we are going to
            //check 2words at a time( 2words->3words-> 4words) which is a DP..
            for (int i = 0; i < s.size() - l; i++)
            {
                int j = i + l; //j will the end of the substring
                if (j - i == 1)
                {
                    //need to consider seperately when j-i=1(can't get the middle substring..)
                    if (s[i] == s[j])
                        pand[i][j] = true;
                }
                else
                {
                    if (s[i] == s[j] && pand[i + 1][j - 1]) //if palindrome of length i-j-1 which start at i+1 exists..and s[i]==s[j]
                        pand[i][j] = true;//then substring of s[i~j] is palindrome..
                }
                if (pand[i][j] && (j-i+1)>cur_max)
                {
                    cur_max = j - i + 1;
                    cur_string = s.substr(i, j - i + 1);//update.. if changed.
                }

            }
        }
           

        return cur_string;

    }
};
int main(void)
{
    Solution s;
    string ans = s.longestPalindrome("bbb");
    cout << ans << endl;


    return 0;
}
