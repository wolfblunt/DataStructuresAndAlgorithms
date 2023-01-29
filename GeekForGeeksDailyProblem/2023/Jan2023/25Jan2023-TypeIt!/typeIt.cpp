#include <bits/stdc++.h>
using namespace std;

// Greedy TC: O(N)
class Solution {
  public:
    int minOperation(string s) {
        int n = s.size();
        bool isOperationDone = false;
        
        int i = n-1;
        int ans=0;
        while(i>=0)
        {
            ans+=1;
            if(i%2==1)  // because index starts at 0
            {
                int index = i/2;
                if(!isOperationDone && s.substr(0, index+1) == s.substr(index+1, i-index))
                {
                    i = index+1;
                    isOperationDone = true;
                }
            }
            i--;
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}