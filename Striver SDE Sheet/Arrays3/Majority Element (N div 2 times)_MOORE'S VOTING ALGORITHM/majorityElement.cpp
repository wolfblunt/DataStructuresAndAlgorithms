// Majority Element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int element;
        for(auto a: nums)
        {
            if(count==0)
            {
                element = a;
            }
            if(element==a)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return element;
    }
};