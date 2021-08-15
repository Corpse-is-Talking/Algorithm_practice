#include<iostream>
#include<vector>
#include<string>
class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x<0)
            return false;
        if(x==0)
            return true;
        string to_check=to_string(x);
        for(int i=0; i<to_check.length(); i++)
        {
            if(to_check[i]!=to_check[to_check.length()-1-i])
                return false;
            
        }
        return true;
        
        
    }
};
int main(void)
{
    Solution s;
    bool result=s.isPalindrome(123454321);
    if(result) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    ///O(n) solution..
}