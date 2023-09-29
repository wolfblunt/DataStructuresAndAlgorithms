// Beautiful tower - O(n^2)

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long ans = 0;
        int n = maxHeights.size();
        for(int i=0;i<n;i++)
        {
            long long last = maxHeights[i];
            long long sum = maxHeights[i];
            for(int j=i-1;j>=0;j--)
            {
                last = min((long long)maxHeights[j], last);
                sum += last;
            }
            
            last = maxHeights[i];
            
            for(int j=i+1;j<n;j++)
            {
                last = min((long long)maxHeights[j], last);
                sum += last;
            }
            
            ans = max(ans, sum);
        }
        
        return ans;
    }
};