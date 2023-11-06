// Min Query

class Solution {
  public:
    vector<int> minQuery(int N, int q, vector<int> &A, vector<vector<int>> &Queries) {
        vector<vector<int>> bit(N, vector<int>(32,0));
        int sum = 0;
        
        for(int i=0;i<N;i++)
        {
            for(int j=0,j1=1;j<32;j++,j1=j1*2)
            {
                if(A[i] & j1)
                {
                    bit[i][j] = 1;
                }
            }
        }
        
        for(int i=1;i<N;i++)
        {
            for(int j=0;j<32;j++)
            {
                bit[i][j] += bit[i-1][j];
            }
        }
        
        int l1,r1,l2,r2;
        int c1,c2;
        vector<int> ans;
        for(int i=0;i<q;i++)
        {
            l1 = Queries[i][0]-1, r1 = Queries[i][1]-1, l2 = Queries[i][2]-1, r2 = Queries[i][3]-1; // convert into 0 based indexing
            for(int j=0;j<32;j++)
            {
                c1 = bit[r1][j];
                if(l1>0)
                {
                    c1 -= bit[l1-1][j];
                }
                
                c2 = bit[r2][j];
                if(l2>0)
                {
                    c2 -= bit[l2-1][j];
                }
                
                if(c1==(r1-l1+1) || c2==(r2-l2+1))  // OR operation
                {
                    sum += pow(2,j);
                }
            }
            
            ans.push_back(sum);
            sum=0;
        }
        
        return ans;
    }
};