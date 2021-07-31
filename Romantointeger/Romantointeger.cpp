#include<map>
#include<iostream>
#include<string>
class Solution {
public:
    int romanToInt(string s) 
    {
        map<char,int> counter;
        counter['I']=1;
        counter['V']=5;
        counter['X']=10;
        counter['L']=50;
        counter['C']=100;
        counter['D']=500;
        counter['M']=1000;
        int sum=0;
        for(int i=0; i<s.length(); i++)
        {
            if(counter[s[i]]<counter[s[i+1]])
            {
                int res=counter[s[i+1]]-counter[s[i]];
                sum+=res;
                i=i+1;
            }
            else
                sum+=counter[s[i]];
        }
        
        return sum;
          
    }
};
int main()
{
    Solution s;
    int ans=s.romanToInt("MCMXCIV");
    cout<<ans<<endl;
    return  0;
}