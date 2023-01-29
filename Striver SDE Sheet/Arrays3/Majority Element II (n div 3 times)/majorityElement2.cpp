// Majority Element (>N/3 times)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int num1 = INT_MIN;
        int num2 = INT_MIN;
        int n = nums.size();
        for(auto a: nums)
        {
            if(a==num1)
            {
                count1++;
            }
            else if(a==num2)
            {
                count2++;
            }
            else if(count1==0)
            {
                num1 = a;
                count1=1;
            }
            else if(count2==0)
            {
                num2 = a;
                count2=1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for(auto a:nums)
        {
            if(num1 == a)
            {
                count1++;
            }
            if(num2 == a)
            {
                count2++;
            }
        }
        vector<int> ans;
        if(count1 > n/3)
        {
            ans.push_back(num1);
        }
        if(count2 > n/3)
        {
            ans.push_back(num2);
        }

        return ans;
    }
};