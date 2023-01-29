class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach=0;
        int i = 0;
        for(i=0; i<n && i<=reach;i++)
        {
            reach = max(reach, i+nums[i]);
        }
        if(i==n)
            return true;
        return false;
    }
};