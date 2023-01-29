//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    vector<string> genIp(string &s) {
        vector<string> ipAddress;
        int n = s.length();
        if(n>12)
        {
            ipAddress.push_back("-1");
            return ipAddress;
        }
        for(int i=1;i<n-2;i++)
        {
            for(int j=i+1;j<n-1; j++)
            {
                for(int k=j+1;k<n; k++)
                {
                    string a = s.substr(0,i);
                    //cout<<"a: "<<a;
                    string b = s.substr(i, j-i);
                    //cout<<"\nb: "<<b<<"j: "<<j-1;
                    string c = s.substr(j, k-j);
                    //string c = s[j:k];
                    //cout<<"\nc: "<<c<<"k: "<<k-1;
                    string d = s.substr(k, n-k);
                    //cout<<"\nd: "<<d<<"\n";
                    if(isValid(a) && isValid(b) && isValid(c) && isValid(d))
                    {
                        string ans = a+"."+b+"."+c+"."+d;
                        ipAddress.push_back(ans);
                    }
                }
            }
        }
        return ipAddress;
    }
    
    
    bool isValid(string s)
    {
        int n = s.length();
        if(n>3 || (s[0]=='0' && n>1) || stoi(s)>255 || n==0)
        {
            return false;
        }
            return true;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends