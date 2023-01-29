//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    vector<int> alpha(26,0);
		    string result="";
		    queue<char> q;
		    for(int i=0;i< A.length();i++)
		    {
		        int index = int(A[i])-97;
		        alpha[index]++;
		        if(alpha[index]==1)
		        {
		            q.push(A[i]);
		        }
		        while(alpha[int(q.front())-97]>1 && q.size())
		        {
		            q.pop();
		        }
		        if(!q.empty())
		        {
		            result+=q.front();
		        }
		        else{
		            result.push_back('#');
		        }
		    }
		    return result;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends