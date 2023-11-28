// Diagonal Traverse 2

/*
	
	Algorithm-

1. In the queue for BFS, insert the index for first cell of first row, i.e. {0,0}
2. For each iteration, for the front element in queue push the index for cell just below it only if the current cell is the first in its row.
Then push the index for right neighbour cell (if exists)

*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> ans;

        queue<pair<int,int>> q;
        q.push({0,0});

        while(!q.empty())
        {
            int x = q.front().first; // x-coordinate
            int y = q.front().second; // y-coordinate
            q.pop();

            ans.push_back(nums[x][y]);

            if(y==0 && x+1<n) // checking for below element if y==0
            {
                q.push({x+1, y});
            }

            if(y+1 < nums[x].size()) // checking for right element
            {
                q.push({x, y+1});
            }
        }

        return ans;
    }
};