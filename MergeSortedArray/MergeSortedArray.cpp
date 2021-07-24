class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int m_i=m-1;
        int n_i=n-1;  
        int index=m+n-1;
        while(m_i>=0 && n_i>=0)
        {
            if(nums1[m_i]<nums2[n_i])
            {
                nums1[index]=nums2[n_i];
                n_i--;
                index--;
                
            }
            else
            {
                nums1[index]=nums1[m_i];
                m_i--;
                index--;
            }

    }
        while(n_i>=0)
        {
            nums1[index]=nums2[n_i];
            index--;
            n_i--;
        }
    }
};
int main(void)
{
    vector<int> vec1 ={1,2,3,0,0,0};
    vector<int> vec2={2,5,6};
    int m=3, n=3;
    Solution s;
    vector<int> answ=s.merge(vec1, 3, vec2, 3);
    for(auto & e: answ )
    {
        cout<< c<<" ";
    }
}