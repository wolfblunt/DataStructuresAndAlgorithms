// Scrambled String

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool solve(string a, string b, unordered_map<string, int> &dp)
    {
        if(a==b)
            return true;
            
        if(a.size() <= 1)
            return false;
            
        string temp = a + "$" + b;
        
        if(dp.count(temp))
            return dp[temp];
            
        int n = a.size();
        
        for(int i=1;i<n;i++)
        {
            if((solve(a.substr(0, i) , b.substr(0, i), dp) && solve(a.substr(i, n-i), b.substr(i, n-i), dp)) ||
            (solve(a.substr(0, i), b.substr(n-i, i), dp)) && solve(a.substr(i, n-i), b.substr(0, n-i), dp))
            {
                return dp[temp] = true;
            }
        }
        
        return dp[temp] = false;
    }
    
    
    bool isScramble(string s1, string s2){
        if(s1==s2)
            return true;
        
        if(s1.size()!=s2.size())
            return false;
        
        unordered_map<string, int> dp;
        return solve(s1, s2, dp);
    }    
};


int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}