// Combination Sum II

class Solution {
public:
    vector<vector<int>> result;
    void helperFunc(vector<int>& candidates, int target, int it, vector<int>& v)
    {
        if(target==0)
        {
            result.push_back(v);
        }

        else if(target<0)
        {
            return;
        }
        else
        {
            for(int i=it; i<candidates.size(); i++)
            {
                if(i>it && candidates[i] == candidates[i-1])
                {
                    continue;
                }
                v.push_back(candidates[i]);
                helperFunc(candidates, target-candidates[i], i+1, v);
                v.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        helperFunc(candidates, target, 0, v);
        return result;
    }
};