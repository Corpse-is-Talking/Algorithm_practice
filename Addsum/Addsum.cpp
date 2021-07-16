#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int,int> hash_tbl;
        int index1=0;
        int index2=0;
        for (auto & element: nums)
        {
            if(hash_tbl[target-element]!=0)
            {
                index2=hash_tbl[target-element]-1;
                break;

            }
            else
            {
                hash_tbl[element]=index1+1;
                index1++;

            }
           
        }
        vector<int> ans;
        ans.push_back(index2);
        ans.push_back(index1);
        return ans;

    }
};
int main(void)
{
    vector<int> nums={2,7, 11,15};
    int target=9;
    vector<int> ans;
    Solution s;
    ans=s.twoSum(nums,target);
    cout<<"["<<ans[0]<<" "<<ans[1]<<"]"<<endl;


    return 0;
}