// Single Number II

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = 32;
        vector<int> arr(n+1, 0);

        int t = nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<t;j++)
            {
                if((nums[j] & (1<<i)) != 0)
                {
                    arr[i]+=1;
                }
            }
        }

        int result = 0;
        for(int i=0;i<n;i++)
        {
            result += (arr[i] % 3) * (1<<i);
        }

        return result;
    }
};