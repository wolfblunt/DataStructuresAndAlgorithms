//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string X, string Y) {
        int n = X.size()-1;
        int m = Y.size()-1;
        int numMin = min(n,m);
        string result="";
        int carry=0;
        int sum;
        while(n>=0 && m>=0)
        {
            sum = (X[n]-'0' + Y[m]-'0'+ carry);
            result+=((sum%10)+'0');
            carry = sum/10;
            n--;
            m--;
        }
        
        while(n>=0)
        {
            sum=(X[n]-'0'+carry);
            result+=((sum%10)+'0');
            carry = sum/10;
            n--;
        }
        
        while(m>=0)
        {
            sum=(Y[m]-'0'+carry);
            result+=((sum%10)+'0');
            carry = sum/10;
            m--;
        }
        
        if(carry>0)
        {
            result+=(carry+'0');
        }
        while(result.back()=='0')
        {
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        
        if(result.size()==0)
        {
            result="0";
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends