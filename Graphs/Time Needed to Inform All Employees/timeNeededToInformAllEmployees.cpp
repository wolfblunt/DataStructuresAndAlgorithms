// Time Needed to Inform All Employees

class Solution {
public:
    unordered_map<int, vector<int>> um;
    int mx = 0;
    int ans = 0;
    void dfs(int manager, vector<int>& informTime)
    {
        mx = max(mx, ans);
        for(auto employee: um[manager])
        {
            ans += informTime[manager];
            dfs(employee, informTime);
            ans -= informTime[manager];
        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
            {
                um[manager[i]].push_back(i);
            }
        }
        dfs(headID, informTime);
        return mx;
    }
};