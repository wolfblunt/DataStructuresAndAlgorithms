class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            if(!dq.empty() && dq.front()==(i-k))
            {
                dq.pop_front();
            }
            while(!dq.empty() && nums[i]>=nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1)
            {
                v.push_back(nums[dq.front()]);   
            }
        }
        return v;
        
    }
};