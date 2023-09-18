// Minimum Right Shifts to Sort the Array

class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        for (int k = 0; k < n; k++) 
        {
            bool possible = true;
            for (int i = 0; i < n; ++i) 
            {
                if (nums[i] != temp[(i + k) % n]) 
                {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                return k;
            }
        }

        return -1;
    }
};