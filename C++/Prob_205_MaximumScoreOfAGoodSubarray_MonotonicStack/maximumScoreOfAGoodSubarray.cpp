// Maximum Score of a Good Subarray

class Solution {
public:
    void helperPreviousSmaller(vector<int>& nums, vector<int> &previousSmaller, int n)
    {
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && nums[s.top()] >= nums[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                previousSmaller.push_back(-1);
            }
            else
            {
                previousSmaller.push_back(s.top());
            }
            s.push(i);
        }
    }

    void helperNextSmaller(vector<int>& nums, vector<int> &nextSmaller, int n)
    {
        stack<int> s;
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && nums[s.top()] >= nums[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                nextSmaller.push_back(n);
            }
            else
            {
                nextSmaller.push_back(s.top());
            }
            s.push(i);
        }
    }

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> previousSmaller;
        vector<int> nextSmaller;
        helperPreviousSmaller(nums, previousSmaller, n);
        helperNextSmaller(nums, nextSmaller, n);
        reverse(nextSmaller.begin(), nextSmaller.end());

        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(previousSmaller[i]<k && nextSmaller[i]>k)
            {
                ans = max(ans, nums[i]*(nextSmaller[i]-previousSmaller[i]-1));
            }
        }

        return ans;
    }
};