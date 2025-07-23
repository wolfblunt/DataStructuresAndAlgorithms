// Sum of Subarray Ranges - O(N)*2 + O(N)*2 = O(N)

class Solution {
public:
    long long subArrayMinimumContribution(vector<int>& nums)
    {
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

        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            ans = ans + ((long long)(nextt[i]-i)*(i-prev[i])*nums[i]);
        }

        return ans;
    }

    long long subArrayMaximumContribution(vector<int>& nums)
    {
        int n = nums.size();
        stack<int> s;
        vector<int> prev(n);
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && nums[s.top()] <= nums[i])
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
            while(!s.empty() && nums[s.top()] < nums[i])
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
        
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            ans = ans + ((long long)(nextt[i]-i)*(i-prev[i])*nums[i]);
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sumMinimum = subArrayMinimumContribution(nums);
        long long sumMaximum = subArrayMaximumContribution(nums);
        long long ans = sumMaximum - sumMinimum;
        return ans;
    }
};