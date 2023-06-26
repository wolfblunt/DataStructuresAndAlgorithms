// Longest Arithmetic Progression

#include <bits/stdc++.h>
using namespace std;


class Solution{   
public:
    int lengthOfLongestAP(int nums[], int n) {
        if(n==1)
            return 1;
            
        unordered_map<int,int> um;
        int ans = 2;
        
        for(int i=0;i<n;i++)
        {
            um[nums[i]]++;    
        }
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int diff = nums[j] - nums[i];
                int s = nums[j];
                int count = 2;
                while(um.find(diff+s) != um.end())
                {
                    count++;
                    s = diff + s;
                }
                ans = max(ans, count);
            }
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}