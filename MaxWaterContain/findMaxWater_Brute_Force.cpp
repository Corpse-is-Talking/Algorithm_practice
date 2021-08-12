#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        //brute force this one is totally brute foce with O(n^2): didnt pass leetcode time limit
        int max_water = 0;
        //for (int i = 0; i < height.size(); i++)
        //{
        //    int left = height[i];
        //    for (int j = i+1; j < height.size(); j++)
        //    {
        //        int width = j - i;
        //        int cur_height= min(left, height[j]);
        //        int cur_capa = width * cur_height;
        //        if (cur_capa > max_water)
        //            max_water = cur_capa;
        //    }

        //}


        //improved this will be lesser than O(n^2 )but still takes alot of time passed a time limit..
        int max_left = -1;
        max_water = max_left;
        for (int i = 0; i < height.size(); i++)
        {
            if (max_left >= height[i])
                continue;

            int cur_left = height[i];
            for (int j = i + 1; j < height.size(); j++)
            {
                int width = j - i;
                int cur_height = min(cur_left, height[j]);
                int cur_capa = width * cur_height;
                if (cur_capa > max_water)
                {
                    max_water = cur_capa;
                    max_left = height[i];
                }
            }

        }


        return max_water;


    }
};
int main()
{
    Solution s;
    vector<int> height= {1,8,6,2,5,4,8,3,7};
    int ans=s.maxArea(height);
    cout << ans << endl;
    return 0;
}