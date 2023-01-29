#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    vector<int> findRange(string str, int n) {
        int low=0,high=0, max=0;
        int sum=0;
        int left=-1, right=-1;
        // Using Kadane's Algorithm
        for(low=0,high=0;high<n;high++)
        {
            if(str[high]=='0')
            {
                sum+=1;
            }
            else
            {
                sum=sum-1;
            }
            if(sum>max)
            {
                max=sum;
                left=low;
                right=high;
            }
            if(sum<0)
            {
                low=high+1;
                sum=0;
            }
        }
        if(left==-1)
        {
            return {-1};
        }
           
        return {left+1,right+1};
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}