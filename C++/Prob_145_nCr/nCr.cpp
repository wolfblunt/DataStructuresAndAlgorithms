// nCr

class Solution{
public:
    int nCr(int n, int r){
        int res = 1;
        for(int i=1;i<=r;i++)
        {
            res = res * (n-r+i)/i;
        }
        return res;
    }
};