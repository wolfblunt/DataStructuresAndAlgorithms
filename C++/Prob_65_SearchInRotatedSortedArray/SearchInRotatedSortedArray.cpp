class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int answer=-1;
        if(r==1)
        {
            if(nums[0] == target)
            {
                return 0;
            }
            else if(nums[1]==target)
            {
                return 1;
            }
            else{
                return -1;
            }
        }

        
        while(l<=r)
        {
            int m = (l+r)/2;
            if(nums[m]==target)
            {
                return m;
            }

            if(nums[l] <= nums[m])
            {
                if(target>=nums[l] && target<=nums[m])
                {
                    r=m-1;
                }
                else
                {
                    l=m+1;
                }
            }
            else
            {
                if(target>=nums[m] && target<=nums[r])
                {
                    l=m+1;
                }
                else
                {
                    r=m-1;
                }
            }
        }

        return answer;
    }
};