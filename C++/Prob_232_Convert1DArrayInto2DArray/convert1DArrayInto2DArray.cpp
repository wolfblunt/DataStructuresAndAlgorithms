// Convert 1D Array Into 2D Array

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size())
        {
            return {};
        }
        vector<vector<int>> v(m, vector<int>(n));
        int t = original.size();
        for(int i=0;i<t;i++)
        {
            v[i/n][i%n] = original[i];
        }
        return v;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();