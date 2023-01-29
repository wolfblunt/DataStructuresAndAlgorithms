// Akku and Binary Numbers

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    
/*
    Approach:
    1. We run three for loops which eventually gives us the number desired number having the 3 set bits.
    2. Each for loop is starting from the multiple of 2 previous for loop as OR Operation of i , j and k.
    3. The number formed we have to simply check its in our range or not.

    Do dry run - if not getting
*/
    
    long long solve(long long l, long long r){
        long long answer=0;
        for(long long i=1;i<=r;i*=2)
        {
            for(long long j=i*2;j<=r;j*=2)
            {
                for(long long k=j*2;k<=r;k*=2)
                {
                    long long no_with_3_bits = i | j | k;
                    if(no_with_3_bits >= l && no_with_3_bits <= r)
                    {
                        answer++;
                    }
                }
            }
        }
        return answer;
    }
    
};


int main()
{
    int t;
    Solution ob;
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    }
    return 0;
}