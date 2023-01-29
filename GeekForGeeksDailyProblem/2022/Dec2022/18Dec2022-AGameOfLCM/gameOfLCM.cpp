#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    
    long long gcd(long long a, long long b)
    {
        if(b==0)
            return a;
        return gcd(b,a%b);
    }
    
    long long helper(long long n)
    {
        int count = 0;
        long long maxLCM = n;
        for(int i=n-1;i>=1;i--)
        {
            if(gcd(maxLCM, i)==1)
            {
                maxLCM*=i;
                count++;
            }
            if(count==3)
                return maxLCM;
        }
        return maxLCM;
    }
    
    long long maxLCM(int N) {
        return max(helper(N),helper(N-1));
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxLCM(N) << "\n";
    }
}