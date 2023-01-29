#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long int xorr = Arr[0];
        for(int i=1;i<N;i++)
        {
            xorr = xorr^Arr[i];
        }
        long long int x = 0;
        long long int y = 0;
        long long int setBit = xorr & ~(xorr-1);
        for(int i=0;i<N;i++)
        {
            if(Arr[i] & setBit)
            {
                x = x^Arr[i];
            }
        }
        
        y = xorr^x;
        vector<long long int> res{x,y};
        sort(res.begin(), res.end() , greater<int>());
        return res;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}