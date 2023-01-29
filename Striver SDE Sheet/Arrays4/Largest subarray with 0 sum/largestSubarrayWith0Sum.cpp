// Largest subarray with 0 sum

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int, int> um;
        int start=0;
        int end = 0;
        int currSum = 0;
        int sum = 0;
        int length=0;
        
        for(int i=0;i<n;i++)
        {
            currSum+=A[i];
            if(currSum-sum==0)
            {
                start=0;
                end = i;
                length = max(length, end)+1;
                um[currSum] = i;
            }
            if(um.find(currSum-sum) == um.end())
            {
                um[currSum-sum] = i;
            }
            else
            {
                start = um[currSum-sum];
                end = i;
                length = max(length, end-start);
            }
        }
        return length;
    }
};