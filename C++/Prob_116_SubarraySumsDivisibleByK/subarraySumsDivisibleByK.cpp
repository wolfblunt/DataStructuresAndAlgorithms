// Subarray Sums Divisible by K

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        vector<int> frequency(k,0);
        frequency[0] = 1;
        int sum = 0;
        for(auto a: nums)
        {
            sum += a;
            int rem = sum%k;
            if(rem < 0)
                rem += k;
            count += frequency[rem];
            frequency[rem]++;
        }
        return count;
    }
};