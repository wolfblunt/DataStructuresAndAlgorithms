// Largest rectangular sub-matrix whose sum is 0 - O((n*m)^2) + O(n*m)

class Solution{
  public:
    int findSum(int r1, int c1, int r2, int c2, int n, int m, vector<vector<int>> &pref)
    {
        int sum = pref[r2][c2];
        if((c1 - 1) >= 0)
        {
            sum -= pref[r2][c1 - 1];
        }
        if((r1 - 1) >= 0)
        {
            sum -= pref[r1 - 1][c2];
        }
        if((c1 - 1) >= 0 && (r1 - 1) >= 0)
        {
            sum += pref[r1 - 1][c1 - 1];
        }
        return sum;
    }
    vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
        int n = a.size(), m = a[0].size();
        vector<vector<int>> pref(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)
        { //right side
            for(int j = 0; j < m; j++)
            {
                pref[i][j] = a[i][j];
                if((j - 1) >= 0)
                {
                    pref[i][j] += pref[i][j - 1];
                }
            }
        }
        for(int j = 0; j < m; j++)
        { //bottom
            for(int i = 0; i < n; i++){
                if((i - 1) >= 0)
                {
                    pref[i][j] += pref[i - 1][j];
                }
            }
        }
        
        vector<int> subMatrix(4, 0);
        int ans= 0;
        for(int r1 = 0;r1<n;r1++)
        {
            for(int c1 = 0;c1<m;c1++)
            {
                for(int r2=r1; r2<n;r2++)
                {
                    for(int c2=c1;c2<m;c2++)
                    {
                        int sum = findSum(r1,c1,r2,c2,n,m,pref);
                        if(sum == 0)
                        {
                            int submatrixSize = (r2-r1+1)*(c2-c1+1);
                            if(submatrixSize > ans)
                            {
                                ans = submatrixSize;
                                subMatrix = {r1,c1,r2,c2};
                            }
                            else if(submatrixSize == ans)
                            {
                                if(c1 < subMatrix[1])
                                {
                                    subMatrix = {r1,c1,r2,c2};
                                }
                                else if(c1 == subMatrix[1] && (r2-r1+1) > (subMatrix[2]-subMatrix[0]+1))
                                {
                                    subMatrix = {r1,c1,r2,c2};
                                }
                                else if(c1 == subMatrix[1] && (r2-r1+1) == (subMatrix[2]-subMatrix[0]+1) && r1 < subMatrix[0])
                                {
                                    subMatrix = {r1,c1,r2,c2};
                                }
                            }
                        }
                    }
                }
            }
        }
        
        vector<vector<int>> result;
        if(ans == 0)
        {
            return result;
        }
        int r1 = subMatrix[0];
        int c1 = subMatrix[1];
        int r2 = subMatrix[2];
        int c2 = subMatrix[3];
        
        result.resize(r2-r1+1, vector<int>(c2-c1+1));
        
        for(int i=r1;i<=r2;i++)
        {
            for(int j=c1;j<=c2;j++)
            {
                result[i-r1][j-c1] = a[i][j];
            }
        }
        
        return result;
    }
};