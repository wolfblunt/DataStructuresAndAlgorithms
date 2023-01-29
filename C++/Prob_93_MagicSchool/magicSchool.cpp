// Magic School

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    while(b)
    {
        int temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}

int helper(vector<int> &A, int B)
{
    int maxN = INT_MIN;
    for(int i=0;i<A.size();i++)
    {
        maxN = max(maxN, A[i]);
    }
    int gcdN = maxN - A[0];
    for(int i=0;i<A.size();i++)
    {
        gcdN = gcd(gcdN, A[i]);
    }
    
    if(B%gcdN==0)
        return 1;
    return 0;
}

int main()
{
    vector<int> A{5,10,15,20,25};
    int B = 5;
    cout<<helper(A,B);

    return 0;
}