// Minimum Operations to Make Array Equal II

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long n = nums1.size();
        if(nums1==nums2)  // nusm1=[1,2,3,4], nums2=[1,2,3,4],  k=0
            return 0;
        if(k==0)  // nusm1=[1,2,3,4], nums2=[6,2,1,6],  k=0
            return -1;
        
        long long result = 0;
        vector<long long> pos;
        vector<long long> neg;
        // int flag = 1;
        for(long long i=0;i<n;i++)
        {
            long long temp = nums1[i]-nums2[i];
            
            if(temp > 0)
                pos.push_back(temp);
            if(temp < 0)
                neg.push_back(temp);
            
            if(temp%k!=0)
            {
                return -1;
            }
        }
        long long spos = 0;
        for(long long i=0;i<pos.size();i++)
        {
            spos += pos[i];
        }
        long long sneg = 0;
        for(long long i=0;i<neg.size();i++)
        {
            sneg += neg[i];
        }
        if(spos + sneg!=0 || k==0)
            return -1;
        
        return spos/k;
    }
};