#include <bits/stdc++.h>
using namespace std;
// O(logn)
class Solution {
  public:
    int checkBaseEquivalence(int n, int a)
    {
        int count = 0;
        while(n>0)
        {
            count+=1;
            n=n/a;
        }
        return count;
    }
    
    string baseEquiv(int n, int m){
        for(int i=2;i<=32;i++)
        {
            if(checkBaseEquivalence(n,i)==m)
            {
                return "Yes";
            }
        }
        return "No";
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        cout<<ob.baseEquiv(n,m)<<endl;
    }
    return 0;
}