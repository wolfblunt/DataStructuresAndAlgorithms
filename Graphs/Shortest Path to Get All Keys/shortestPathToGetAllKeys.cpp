// Shortest Path to Get All Keys  - time: O(m*n*2^k) where k is keys

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int x = -1, y = -1;
        int n = grid.size(), m = grid[0].size();
        int max_len = -1;  // number of keys in grid
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                char c = grid[i][j];
                if(c == '@')
                {
                    // storing the coordinates of starting position
                    x = i;
                    y = j;
                }

                if(c >= 'a' && c <= 'f') // checking key should lie between a<=key<=f
                {
                    max_len = max(c-'a'+1, max_len);  // if char=d then max_len = (d-a)+1 = 3+1 = 4
                }
            }
        }

        vector<int> start = {0, x, y}; // storing {npOfKeysCollected, cord_x, cord_y}
        queue<vector<int>> q;  // pair is faster than vector in runtime
        unordered_set<string> visited;
        visited.insert(to_string(0) + " " + to_string(x) + " " + to_string(y)); // keysx y
        q.push(start);
        int steps = 0;
        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        while(!q.empty())
        {
            int size = q.size();
            for(int k=0;k<size;k++)
            {
                vector<int> curr = q.front();
                q.pop();
                if(curr[0] == (1 << max_len)-1) // if all the keys are collected
                {
                    return steps;
                }

                for(auto &d: dirs)
                {
                    int new_x = curr[1] + d[0];
                    int new_y = curr[2] + d[1];
                    int keys = curr[0];  // contains the sum of all the keys in 2^power index
                    if(new_x >=0 && new_x<n && new_y>=0 && new_y<m)
                    {
                        char c = grid[new_x][new_y];
                        if(c == '#')
                        {
                            continue;  // if it is a wall then we can't visit, so continue
                        }
                        if(c>='a' && c<='f')
                        {
                            keys = keys | 1<<(c-'a');  // adding the key into keys.
                        }
                        if(c>='A' && c<='F' && ((keys >> (c-'A')) & 1) == 0)
                        {
                            continue;  // means the particular key is not present to open the lock
                        }
                        if(!visited.count(to_string(keys)+" "+to_string(new_x)+" "+to_string(new_y)))
                        {
                            visited.insert(to_string(keys)+" "+to_string(new_x)+" "+to_string(new_y));
                            q.push({keys, new_x,new_y});
                        }
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};