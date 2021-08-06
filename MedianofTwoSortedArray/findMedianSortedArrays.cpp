#include<iostream>
#include<vector>
#include<algorithm>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]>nums2[j])
                ans.push_back(nums1[i++]);
            else    
                ans.push_back(nums2[j++]);
            
        }
        while(i<nums1.size())
        {
            ans.push_back(nums1[i++]);
        }
        while(j<nums2.size())
        {
            ans.push_back(nums2[i++]);
        }
        int ans_size=nums1.size()+nums2.size();
        if(ans_size%2!=0)
            return ans[ans_size/2];
        else
            return double(ans[ans_size/2]+ans[(ans_size/2)-1])/2.0;



        
    }
};