// 3 Divisors
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    
    void sievePrime(long long nn, vector<int> &primeVector)
    {
        int n = (int)sqrt(nn);
        vector<bool> prime(n+1,true);
        for(long long i=2;i<=n;i++)
        {
            if(prime[i])
            {
                for(long long j=2*i;j<=n;j+=i)
                {
                    prime[j] = false;
                }
            }
        }
        
        for(int i=2;i<=n;i++)
        {
            primeVector[i] = primeVector[i-1];
            if(prime[i])
            {
                primeVector[i]+=1;
            }
        }
    }
    
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        int n = 1e6;
        vector<int> primeVector(n+1,0);  // dp array
        sievePrime(n, primeVector);
        vector<int> answer;
        for(int i=0;i<q;i++)
        {
            int sq = floor(sqrt(query[i]));
            answer.push_back(primeVector[sq]);
        }
        return answer;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends