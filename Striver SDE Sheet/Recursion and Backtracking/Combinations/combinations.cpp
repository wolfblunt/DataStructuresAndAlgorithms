// Combinations

class Solution {
public:
    void backtrack(int n, int k, int start, vector<int> &combination, vector<vector<int>>& answer)
    {
        if(combination.size() == k)
        {
            answer.push_back(combination);
            return;
        }

        for(int i=start;i<=n;i++)
        {
            combination.push_back(i);
            backtrack(n,k,i+1,combination,answer);
            combination.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> answer;
        vector<int> combination;
        backtrack(n, k, 1, combination, answer);
        return answer;
    }
};