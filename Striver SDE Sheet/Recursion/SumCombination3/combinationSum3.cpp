// Combination Sum III

class Solution {
public:
    void helperFunc(vector<vector<int>> &result, vector<int> &v, int k, int n)
    {
        if(v.size()==k && n==0)
        {
            result.push_back(v);
            return;
        }
        if(v.size()<k)
        {
            for(int i=v.empty() ? 1 : v.back()+1; i<=9; i++)
            {
                if(n-i < 0)
                    break;
                v.push_back(i);
                helperFunc(result, v, k, n-i);
                v.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        vector<vector<int>> result;
        helperFunc(result, v, k, n);
        return result;
    }
};