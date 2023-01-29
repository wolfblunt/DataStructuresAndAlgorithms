class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> prefixSum;
        sort(nums.begin(), nums.end());
        int s=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            prefixSum.push_back(s);
        }

        vector<int> result(queries.size(), 0);
        for(int i=0;i<queries.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(prefixSum[j] <= queries[i])
                {
                    result[i] = j+1;
                }
                else
                {
                    break;
                }
            }
        }

        return result;
    }
};