// Pow(x, n)

class Solution {
public:
    double myPow(double x, int nn) {
        int sign = 0;
        double ans=1.0;
        long long n = nn;
        if(n<0)
        {
            sign=1;
            n = -1*n;
        }
        while(n)
        {
            if(n%2)
            {
                ans*=x;
                n=n-1;
            }
            else
            {
                x=x*x;
                n=n/2;
            }
        }
        cout<<ans;
        if(sign)
        {
            ans = (double)(1.0)/(double)ans;
        }
        return ans;
    }
};