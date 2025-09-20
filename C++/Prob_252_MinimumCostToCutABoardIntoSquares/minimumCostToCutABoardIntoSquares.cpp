// Minimum Cost to cut a board into squares: O(n+m)

class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());
        int i = 0;
        int j = 0;
        int verticalBlocks = 1;
        int horozontalBlocks = 1;
        int ans = 0;
        while(i<m-1 && j<n-1)
        {
            if(x[i] > y[j])
            {
                ans += (horozontalBlocks*x[i]);
                verticalBlocks++;
                i++;
            }
            else
            {
                ans += verticalBlocks*y[j];
                horozontalBlocks++;
                j++;
            }
        }
        
        while(i < m-1)
        {
            ans += horozontalBlocks*x[i];
            verticalBlocks++;
            i++;
        }
        
        while(j < n-1)
        {
            ans += verticalBlocks*y[j];
            horozontalBlocks++;
            j++;
        }
        
        return ans;
    }
};