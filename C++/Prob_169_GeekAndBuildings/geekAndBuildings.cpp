// Geek and Buildings
// Video Solution Link - https://www.youtube.com/watch?v=osv_1dBiFI0&ab_channel=GeeksforGeeksPractice

class Solution{
    public:
    vector<long long> nextGreaterElement(int n, vector<int> &heights)
    {
        stack<int> s;
        vector<long long> next;
        next.push_back(-1);
        s.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!s.empty() && heights[s.top()] < heights[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                next.push_back(-1);
            }
            else
            {
                next.push_back(s.top());
            }
            s.push(i);
        }
        reverse(next.begin(), next.end());
        return next;
    }
    
    long long maximum_energy(int n, vector<int> &heights){
        vector<long long> next = nextGreaterElement(n, heights); // stores next greater element
        vector<long long> dp(n, -1);
        // dp[index] will store the maximum energy start from that index till last
        long long ans = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(next[i]==-1)
            {
                dp[i] = heights[i];
            }
            else
            {
                dp[i] = heights[i] ^ dp[next[i]];
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};