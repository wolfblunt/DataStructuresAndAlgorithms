// Print matrix in diagonal pattern

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         vector<int> ans;
         bool flag = true;
         int n = mat.size();
         for(int i=0;i<n;i++)
         {
             int start = ans.size();
             int x = 0;
             int y = i;
             while(x<n && y>=0)
             {
                 ans.push_back(mat[x][y]);
                 x++;
                 y--;
             }
             if(flag)
             {
                 reverse(ans.begin()+start, ans.end());
             }
             
             flag = !flag;
         }
         
         for(int i=1;i<n;i++)
         {
             int start = ans.size();
             int x = i;
             int y = n-1;
             while(x<n && y>=0)
             {
                 ans.push_back(mat[x][y]);
                 x++;
                 y--;
             }
             if(flag)
             {
                 reverse(ans.begin()+start, ans.end());
             }
             
             flag = !flag;
         }
         
         return ans;
    }
};