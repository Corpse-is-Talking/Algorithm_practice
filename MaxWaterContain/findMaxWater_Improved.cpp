#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height)
    {

        //improved
        int max_water = 0;
        int i = 0;
        int j = height.size()-1;
        while (i < j)
        {
            int cur_width = j - i;
            int cur_height = min(height[i], height[j]);
            int cur_water = cur_width * cur_height;
            if (max_water < cur_water) max_water = cur_water;
            if (height[i] > height[j]) j--;
            else i++;

        }


        return max_water;


    }
};