#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    
    int numberOfSubsequences(string S, string W){
        int n = S.length();
        int m = W.length();
        int ans=0;
        for(int i=0;i<n;i++){
            int j=i;
            if(S[i]==W[0]){
                int k=0;
                while(j<n){
                    if(S[j]==W[k]){
                        S[j]='!';
                       k++;
                    }
                    j++;
                }
                if(k==W.size()){
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
}