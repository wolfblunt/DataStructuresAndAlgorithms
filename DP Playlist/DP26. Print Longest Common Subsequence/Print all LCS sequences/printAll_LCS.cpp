// Print all LCS sequences
// link - https://practice.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	    int lcs(string &s, string &t, int index1, int index2, vector<vector<int>> &dp)
	    {
	        if(index1<0 || index2<0)
	            return 0;
	           
	        if(dp[index1][index2]!=-1)
	            return dp[index1][index2];
	       
	        if(s[index1]==t[index2])
	        {
	            int match = 1 + lcs(s,t,index1-1,index2-1,dp);
	            return dp[index1][index2] = match;
	        }
	        int notMatch = 0 + max(lcs(s,t,index1-1,index2,dp) , lcs(s,t,index1,index2-1,dp));
	        return dp[index1][index2] = notMatch;
	    }
	    
	    // backtracking
	    void helper(string &s, string &t, string temp, int i, int j, vector<string> &lcsString, int len, int n, int m)
	    {
	        if(len==0)
	        {
	            lcsString.push_back(temp);
	            return;
	        }
	        
	        for(int k=i;k<n;k++)
	        {
	            for(int l=j;l<m;l++)
	            {
	                if(s[k]==t[l])
	                {
	                    temp.push_back(s[k]);
	                    helper(s,t,temp,k+1,l+1,lcsString, len-1, n,m);
	                    temp.pop_back();
	                }
	            }
	        }
	    }
	    
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    int n = s.length();
		    int m = t.length();
		    vector<vector<int>> dp(n, vector<int>(m, -1));
		    lcs(s,t, n-1, m-1, dp);
		    int i=n-1;
		    int j=m-1;
		    int len=dp[i][j];
		    vector<string> lcsString;
		    string ss="";
		    helper(s,t,ss,0,0,lcsString,len,n,m);
		    set<string> s1(lcsString.begin(), lcsString.end());
		    lcsString.assign(s1.begin(), s1.end());
		    return lcsString;
		}
		
		
};


int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}