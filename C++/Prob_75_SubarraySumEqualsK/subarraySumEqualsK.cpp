class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int answer=0;
        um[0]=1;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(um.find(sum-k)!=um.end())
            {
                answer += um[sum-k];
            }
            um[sum]+=1;
        }
        return answer;
    }
};