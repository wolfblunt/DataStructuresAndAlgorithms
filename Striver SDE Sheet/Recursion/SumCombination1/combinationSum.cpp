// Combination Sum

class Solution {
public:
    vector<vector<int>> result;
    void helperFunc(vector<int>& candidates, int target, int it, vector<int>& v)
    {
        if(target==0)
        {
            result.push_back(v);
            return;
        }

        if(target<0)
        {
            return;
        }

        if(it==candidates.size())
        {
            return;
        }

        helperFunc(candidates, target, it+1, v);
        v.push_back(candidates[it]);
        helperFunc(candidates, target-candidates[it], it, v);
        v.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        vector<int> v;
        helperFunc(candidates, target, 0, v);
        return result;
    }
};