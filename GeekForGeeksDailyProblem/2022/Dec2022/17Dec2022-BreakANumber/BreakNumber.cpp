// Break a number

#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    int waysToBreakNumber(int N){
         long long int n = N;
         long long int mod = 1e9+7;
         return (((n-1)*(n+4)+6)/2)%(mod);
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.waysToBreakNumber(N) << endl;
    }
    return 0; 
}