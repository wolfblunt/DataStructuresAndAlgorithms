// Sum of Subarray Minimums - O(n)

class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> prev(n);
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && nums[s.top()] >= nums[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                prev[i] = -1;
            }
            else
            {
                prev[i] = s.top();
            }
            s.push(i);
        }

        while (!s.empty()) {
            s.pop();
        }
        vector<int> nextt(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && nums[s.top()] > nums[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                nextt[i] = n;
            }
            else
            {
                nextt[i] = s.top();
            }
            s.push(i);
        }

        const int mod = 1e9+7;
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            ans = ans%mod + ((long long)(nextt[i]-i)*(i-prev[i])*nums[i])%mod;
        }

        return ans%mod;
    }
};