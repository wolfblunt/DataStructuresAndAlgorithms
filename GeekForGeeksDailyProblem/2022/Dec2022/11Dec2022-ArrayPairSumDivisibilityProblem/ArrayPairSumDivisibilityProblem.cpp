// Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs 
// such that sum of every pair is divisible by k.
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        vector<int> rem;
        int n = nums.size();
        if(n%2)
        {
            return false;
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            int r = nums[i]%k;
            if(r==0)
            {
                count++;
            }
            else
            {
                rem.push_back(r);
            }
        }
        if(count%2)
        {
            return false;
        }
        sort(rem.begin(), rem.end());
        
        int start = 0;
        int vs = rem.size();
        int end = vs-1;
        while(start<end)
        {
            if(rem[start]+rem[end]!=k)
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}