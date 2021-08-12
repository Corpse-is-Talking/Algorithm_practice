#include<iostream>
#include<vector>
#include<algorithm>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        
        int size1=nums1.size();
        int size2=nums2.size();
        int start=0;
        int end=size1;
        if(size1>size2)
            return findMedianSortedArrays(nums2,nums1);
        bool isOdd=false;
        if((size1+size2)%2!=0)
            isOdd=true;
        int maxl1=0;
        int minr1=0;
        int minr2=0;
        int maxl2=0;
        while(start<=end)
        {
            int partition1=(start+end)/2;
            int partition2=((size1+size2+1)/2)-partition1;
            int maxLeft1=(partition1==0)?INT_MIN:nums1[partition1-1];
            int minRight1=(partition1==size1)?INT_MAX:nums1[partition1];
            int maxLeft2=(partition2==0)?INT_MIN:nums2[partition2-1];
            int minRight2=(partition2==size2)?INT_MAX:nums2[partition2];

            if(maxLeft1<=minRight2&& maxLeft2<=minRight1)
            {   
                maxl1=maxLeft1;
                maxl2=maxLeft2;
                minr1=minRight1;
                minr2=minRight2;
                break;

            }
            else if(maxLeft1>minRight2)
            {
                end=partition1-1;
            }
            else
            {
                start =partition1+1;

            }
                
        }
        if(isOdd) return max(maxl1,maxl2);
        else return double(max(maxl1,maxl2)+min(minr1,minr2))/2;

        
    }
};