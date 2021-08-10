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
        vector<vector<bool> > pand(s.size(), vector<bool>(s.size(), false));
        string cur_string = "";
        cur_string += s[0];
        for (int i = 0; i < s.size(); i++)
        {
            pand[i][i] = true;
        }
        int cur_max = 1;
        for (int l = 1; l <= s.size(); l++)
        {
            for (int i = 0; i < s.size() - l; i++)
            {
                int j = i + l;
                if (j - i == 1)
                {
                    if (s[i] == s[j])
                        pand[i][j] = true;
                }
                else
                {
                    if (s[i] == s[j] && pand[i + 1][j - 1])
                        pand[i][j] = true;
                }
                if (pand[i][j] && (j-i+1)>cur_max)
                {
                    cur_max = j - i + 1;
                    cur_string = s.substr(i, j - i + 1);
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
