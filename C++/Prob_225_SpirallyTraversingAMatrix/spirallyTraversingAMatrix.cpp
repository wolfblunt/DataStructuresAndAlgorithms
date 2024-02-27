/**
 *  Given a m * n matrix, print the contents of it spiral way. for example.
 *  Matrix is :
 *      1  2  3  4  5 
 *      6  7  8  9  10
 *      11 12 13 14 15
 *      16 17 18 19 20
 *  Sprial order print would
 *  1 2 3 4 5 10 15 20 19 18 17 16 11 6 7 8 9 14 13 12
 */

// O(n*n)
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> ans;
        int total = r*c;
        int count = 0;
        int sr = 0;
        int er = r-1;
        int sc = 0;
        int ec = c-1;
        
        while(count < total)
        {
            for(int i=sc;count < total && i<=ec;i++)
            {
                ans.push_back(matrix[sr][i]);
                count++;
            }
            sr++;
            
            for(int i=sr;count < total && i<=er;i++)
            {
                ans.push_back(matrix[i][ec]);
                count++;
            }
            ec--;
            
            for(int i=ec;count < total && i>=sc;i--)
            {
                ans.push_back(matrix[er][i]);
                count++;
            }
            er--;
            
            for(int i=er;count < total && i>=sr;i--)
            {
                ans.push_back(matrix[i][sc]);
                count++;
            }
            sc++;
        }
        
        return ans;
    }
};