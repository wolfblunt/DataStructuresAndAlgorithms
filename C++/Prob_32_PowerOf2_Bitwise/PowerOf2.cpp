//1099511627776

//4294967296

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        double d = log2(n);
        if(n==0)
        {
            return false;
        }
        long long temp;
        temp = (long long)d;
        // cout<<"Temp: "<<temp;
        // cout<<"d : "<<d;
        if(d>(double)temp)
        {
            return false;
        }
        else{
            return true;
        }
        
    }
};


int main()
{

    int t;
    cin>>t;//testcases

    for(int i=0;i<t;i++)
    {
        long long n; //input a number n
        cin>>n;

        Solution ob;
         if(ob.isPowerofTwo(n))//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;

    }

    return 0;
}