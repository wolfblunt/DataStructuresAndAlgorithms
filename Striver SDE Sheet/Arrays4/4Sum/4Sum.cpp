// 4Sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> temp;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int left = j+1;
                int right = n-1;
                long long search = target - (long long)(nums[i] + nums[j]);
                while(left<right)
                {
                    vector<int> v;
                    if(search > nums[left] + nums[right])
                    {
                        left++;
                    }
                    else if(search < nums[left] + nums[right])
                    {
                        right--;
                    }
                    else
                    {
                        int a = nums[left];
                        int b = nums[right];
                        temp.insert({nums[i], nums[j], a, b});
                        while(left<right && a==nums[left])
                        {
                            left++;
                        }
                        while(left<right && b==nums[right])
                        {
                            right--;
                        }
                    }
                }
            }
        }
        ans.assign(temp.begin(), temp.end());
        return ans;
    }
};