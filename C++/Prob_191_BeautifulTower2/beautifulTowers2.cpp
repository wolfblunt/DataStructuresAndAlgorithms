// Beautiful Towers II

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        stack<int> st;
        int n = maxHeights.size();
        vector<long long> prefixSum(n, 0);
        vector<long long> suffixSum(n, 0);
        st.push(0);
        prefixSum[0] = maxHeights[0];
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && maxHeights[st.top()] > maxHeights[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                st.push(i);
                prefixSum[i] += 1ll*(i+1)*maxHeights[i];
                continue;
            }
            
            prefixSum[i] += prefixSum[st.top()] + 1ll*(i-st.top())*maxHeights[i];
            st.push(i);
        }
        
        while(!st.empty())
        {
            st.pop();
        }
        st.push(n-1);
        suffixSum[n-1] = maxHeights[n-1];
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && maxHeights[st.top()] > maxHeights[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                suffixSum[i] += 1ll*maxHeights[i]*(n-i);
                st.push(i);
                continue;
            }
            suffixSum[i] += suffixSum[st.top()] + 1ll*(st.top()-i)*maxHeights[i];
            st.push(i);
        }
        
        long long maxSum = 0;
        for(int i=0;i<n;i++)
        {
            maxSum = max(maxSum, suffixSum[i]+prefixSum[i]-maxHeights[i]);
        }
        
        return maxSum;
    }
};