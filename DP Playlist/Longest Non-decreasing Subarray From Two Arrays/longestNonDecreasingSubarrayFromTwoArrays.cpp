// Longest Non-decreasing Subarray From Two Arrays  -  Using DP with space O(n)

class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> dp1(n,1),dp2(n,1);
        int ans = 1;
        
        //dp1[i] tells the max length of subarray ending at index i considering that nums3[i] = nums1[i]. 
        //Similarly dp2[i] tells the max length of subarray ending at index i conidering that nums3[i] = nums2[i]

        for(int i = 1;i<n;i++)
        {
            //if we make nums3[i] = nums1[i] then what max ans can we get
            if(nums1[i-1]<=nums1[i]) 
                dp1[i] = max(dp1[i],1+dp1[i-1]);

            if(nums2[i-1]<=nums1[i])
                dp1[i] = max(dp1[i],1+dp2[i-1]);
            
            //if we make nums3[i] = nums2[i] then what max ans can we get
            if(nums2[i-1]<=nums2[i])
                dp2[i] = max(dp2[i],1+dp2[i-1]);

            if(nums1[i-1]<=nums2[i])
                dp2[i] = max(dp2[i],1+dp1[i-1]);
            
            ans = max({ans,dp1[i],dp2[i]}); //final ans will be max length possible of any subarray
        }
        return ans;
    }
};