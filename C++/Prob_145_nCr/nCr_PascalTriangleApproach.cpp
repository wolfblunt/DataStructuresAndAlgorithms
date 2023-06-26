// nCr - Using Pascal Triangle

class Solution{
public:
    const int mod = 1e9+7;
    int nCr(int n, int r){
        if(n < r)
            return 0;
            
        vector<int> pascal;
        
        for(int i=0;i<=n;i++)
        {
            vector<int> v(i+1, 1);
            for(int j=1;j<i;j++)
            {
                v[j] = (pascal[j-1] + pascal[j]) % mod;
            }
            pascal = v;
        }
        
        return pascal[r];
    }
};