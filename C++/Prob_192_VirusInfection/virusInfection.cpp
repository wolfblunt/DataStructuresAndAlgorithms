// Virus Infection

class Solution{
    public:
    int solve(string s, int k){
        int n = s.length();
        vector<int> count(n,0);  // keep the counter who all are visited
        int last = -1;
        int ans = 0;
        
        // iterating from left to right and keep infected counter ahead values
        for(int i=0;i<n;i++)
        {
            if(s[i] == '1')
            {
                ans++;
                count[i] = 1;
                last = i;
            }
            else
            {
                if(last!=-1)
                {
                    if(i-last <= k)
                    {
                        ans++;
                        count[i] = 1;
                    }
                }
            }
        }
        
        last = -1;
        // iterating from right to left and keep infected counter 
        // right to left of those who are not previously visited
        for(int i=n-1;i>=0;i--)
        {
            if(s[i] == '1')
            {
                if(count[i] == 0)
                {
                    ans++;
                    count[i]=1;
                }
                last = i;
            }
            else
            {
                if(last != -1)
                {
                    if(last-i <= k)
                    {
                        if(count[i] == 0) // if it is not already visited
                        {
                            ans++;
                            count[i] = 1;
                        }
                    }
                }
            }
        }
        
        
        return ans;
    }
};