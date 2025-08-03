// 2D Difference Array: O(N*M) + O(Q)

class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> diff(n, vector<int>(m, 0));
        
        for(auto &a: opr)
        {
            int value = a[0];
            int r1 = a[1];
            int c1 = a[2];
            int r2 = a[3];
            int c2 = a[4];
            
            diff[r1][c1] += value;
            if(r2+1 < n && c1 < m)
            {
                diff[r2+1][c1] -= value;
            }
            if(c2+1<m && r1<n)
            {
                diff[r1][c2+1] -= value;
            }
            if(r2+1 < n && c2+1<m)
            {
                diff[r2+1][c2+1] += value;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                diff[i][j] += diff[i][j-1];
            }
        }
        
        for(int j=0;j<m;j++)
        {
            for(int i=1;i<n;i++)
            {
                diff[i][j] += diff[i-1][j];
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mat[i][j] += diff[i][j]; 
            }
        }
        
        return mat;
    }
};