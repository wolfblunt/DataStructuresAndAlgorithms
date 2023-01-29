#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int NthTerm(int N){
		    int l = N;
		    int r = N;
		    if(N==1)
		    {
		        return 1;
		    }
		    for(int i=2;i<l;i++)
		    {
		        if(l%i==0)
		        {
		            i=1;
		            l--;
		        }
		    }
		    
		    for(int i=2;i<r;i++)
		    {
		        if(r%i==0)
		        {
		            i=1;
		            r++;
		        }
		    }
		    
		    int res = (N-l) > (r-N)?(r-N):(N-l);
		    return res;
		}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		int ans = obj.NthTerm(N);
		cout << ans << "\n";
	}
	return 0;
}