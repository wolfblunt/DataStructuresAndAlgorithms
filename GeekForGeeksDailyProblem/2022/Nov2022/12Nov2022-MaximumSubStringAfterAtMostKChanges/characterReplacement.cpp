#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int characterReplacement(string s, int k){
		    unordered_map<char, int> um;
		    int maxFrequency = 0;
		    int maxLength = 0;
		    int start = 0;
		    int end = 0;
		    
		    while(end<s.length())
		    {
		        um[s[end]]++;
		        maxFrequency = max(maxFrequency, um[s[end]]);
		        if(end-start+1-maxFrequency > k)
		        {
		            um[s[start]]--;
		            start++;
		        }
		        maxLength = max(maxLength, end-start+1);
		        end++;
		    }
		    return maxLength;
		}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}