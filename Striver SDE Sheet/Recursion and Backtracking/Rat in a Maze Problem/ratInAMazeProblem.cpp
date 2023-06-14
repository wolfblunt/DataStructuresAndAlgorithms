// Rat in a Maze Problem

#include <bits/stdc++.h>
using namespace std;



class Solution{
    public:
    void solveMaze(int row, int col, vector<vector<int>> &maze, vector<string> &answer, string move, vector<int> &dr, vector<int> &dc, int n, vector<vector<int>> &visited)
    {
        if(row == n-1 && col == n-1)
        {
            answer.push_back(move);
            return;
        }
        
        string dirs = "DLRU";
        for(int i=0;i<4;i++)
        {
            int new_row = row + dr[i];
            int new_col = col + dc[i];
            if(new_row>=0 && new_row<n && new_col>=0 && new_col<n && !visited[new_row][new_col] && maze[new_row][new_col]==1)
            {
                visited[row][col] = 1;
                solveMaze(new_row, new_col, maze, answer, move+dirs[i], dr, dc, n, visited);
                visited[row][col] = 0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        vector<string> answer;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<int> dr = {1, 0, 0, -1};
        vector<int> dc = {0, -1, 1, 0};
        if(maze[0][0] == 1)
        {
            solveMaze(0, 0, maze, answer, "", dr, dc, n, visited);
        }
        return answer;
    }
};

    


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}