//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        string result="";
        string tempResult="";
        for(int i=S.length()-1; i>=0; i--)
        {
            if(S[i] == '.')
            {
                reverse(tempResult.begin(), tempResult.end());
                result = result + tempResult;
                result.push_back('.');
                tempResult = "";
            }
            else{
                tempResult.push_back(S[i]);
            }
        }
        reverse(tempResult.begin(), tempResult.end());
        result = result + tempResult;
        
        return result;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends