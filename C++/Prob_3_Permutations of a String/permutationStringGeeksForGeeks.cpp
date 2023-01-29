//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void permute(string& s, int l, int r, set<string> &res)
    {
        if(l==r)
        {
            res.insert(s);
            return;
        }
        
        for(int i=l;i<r;i++)
        {
            swap(s[i],s[l]);
            permute(s,l+1,r,res);
            swap(s[i],s[l]);
        }
    }
    
	public:
		vector<string>find_permutation(string S)
		{
		    set<string> res;
		    vector<string> final_res;
		    permute(S, 0,S.length(), res);
		    for(auto it: res){
		        final_res.push_back(it);
		    }
		    return final_res;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends