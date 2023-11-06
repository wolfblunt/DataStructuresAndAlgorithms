// Matchsticks to Square - Using Backtracking

class Solution {
public:
    bool helper(vector<int>& matchsticks, vector<int> &visited, int &target, int sidesRemaining, int index, int squareSide)
    {
        if(sidesRemaining == 0)
        {
            return true;
        }

        if(squareSide == target)
        {
            return helper(matchsticks, visited, target, sidesRemaining-1, 0, 0);
        }

        for(int i=index;i<matchsticks.size();i++)
        {
            if(visited[i] || squareSide+matchsticks[i] > target)
            {
                continue;
            }

            visited[i] = true;
            if(helper(matchsticks, visited, target, sidesRemaining, i+1, squareSide+matchsticks[i]))
            {
                return true;
            }

            visited[i] = false;
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        int n = matchsticks.size();
        for(int i=0;i<n;i++)
        {
            sum += matchsticks[i];
        }

        if(sum%4 != 0)
        {
            return false;
        }

        vector<int> visited(n, false);
        int target = sum/4;
        return helper(matchsticks, visited, target, 3, 0, 0);
    }
};