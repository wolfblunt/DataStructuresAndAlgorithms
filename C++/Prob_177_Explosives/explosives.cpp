// Explosives

class Solution {
  public:
    int maxBoxes(int n, int K, int C, int col[]) {
        int ans=0, sum=0, count=0;
        int i1,j1;
        
        for(int i=0;i<n-1;i++)
        {
            if(col[i] == col[i+1] && col[i] == C)
            {
                sum = 2;
                i1 = i-1;
                j1 = i+2;
                while(i1>=0 && j1<n && col[i1] == col[j1])
                {
                    count=2;
                    i1--;
                    j1++;
                    
                    if(j1<n && col[j1] == col[j1-1])
                    {
                        count++;
                        j1++;
                    }
                    
                    if(i1>=0 && col[i1] == col[i1+1])
                    {
                        count++;
                        i1--;
                    }
                    
                    if(count>=3)
                    {
                        sum += count;
                    }
                    else
                    {
                        break;
                    }
                }
                
                ans = max(ans, sum);
            }
        }
        
        return ans;
    }
};