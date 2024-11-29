// Rotating the Box - O(n*m)
/* Intuition: Treat each column separately. Use a write pointer w initialized to be N - 1. When reading a stone, 
write the stone to w-th row and --w. When reading an obstacle at row row, set w = row - 1. */

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();

        vector<vector<char>> ans(m, vector<char>(n, '.'));

        for(int i=0;i<n;i++)
        {
            int writePointer = m-1;
            for(int j=m-1;j>=0;j--)
            {
                if(box[i][j] == '.')
                {
                    continue;
                }
                else if(box[i][j] == '#')
                {
                    ans[writePointer][n-i-1] = '#';
                    writePointer--;
                }
                else
                {
                    ans[j][n-i-1] = '*';
                    writePointer = j-1;
                }
            }
        }

        return ans;
    }
};