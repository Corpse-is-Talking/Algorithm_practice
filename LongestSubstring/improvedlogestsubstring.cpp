#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> set;
        int i=0, j=0, cur_max=0;
        while(i>0 && j>0)
        {
            if(set.find(s[j])==set.end())
                {
                set.insert(s[j++]);
                cur_max=max(cur_max,j-i);
                }
            else
            {
                set.erase(s[i++]);
            }
        }

    
        return cur_max;

    }
};
int main(void)
{

    string x="abcabcbb"; //should be 3
    string y="bbbb"; //should be 1
    string z="pwwkew"; //should be 3
    string s="";// should be 0
    string t=" "; //should be 1
    Solution a;
    cout<<x<<": " <<a.lengthOfLongestSubstring(x)<<endl;
    cout<<y<<": " <<a.lengthOfLongestSubstring(y)<<endl;
    cout<<z<<": " <<a.lengthOfLongestSubstring(z)<<endl;
    cout<<s<<": " <<a.lengthOfLongestSubstring(s)<<endl;
    cout<<t<<": " <<a.lengthOfLongestSubstring(t)<<endl;

}