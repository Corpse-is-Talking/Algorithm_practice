#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        int curmax=0;
        if(s.length()==0)
            return 0;
        if(s.length()==1)
            return 1;
        int max=0;
        for(int i=0; i<s.length()-1; i++)
        {
            map<int,int> h_map;
            h_map[s[i]]=1;
            curmax=1;
            for(int j=i+1; j<s.length(); j++)
            {
                if(h_map[s[j]]==0)
                {
                    h_map[s[j]]=1;
                    curmax++;
                }
                else
                    break;
            }
            if(curmax>max)
                max=curmax;
        }
        return max;

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