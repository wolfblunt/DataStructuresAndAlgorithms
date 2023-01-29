//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:

    string recur_str(string s)
    {
        int i=0;
        int n = s.size();
        string result;
        while(i<n)
        {
            if(i<n-1 && s[i]==s[i+1])
            {
                while(i<n-1 &&s[i]==s[i+1])
                {
                    i++;
                }
            }
            else{
                result.push_back(s[i]);
            }
            i++;
        }
        return result;
    }
    
    string rremove(string s){
       string temp_s;
       while(temp_s.size()!=s.size())
       {
           temp_s=s;
           s=recur_str(s);
       }
       return s;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends