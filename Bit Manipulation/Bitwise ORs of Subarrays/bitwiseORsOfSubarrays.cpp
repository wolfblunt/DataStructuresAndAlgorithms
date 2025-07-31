// Bitwise ORs of Subarrays - O(NlogM) where M will be maximum 32: So O(N*log32) ≈ O(N)

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> or_ending_prev;
        unordered_set<int> ans;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            unordered_set<int> or_ending_here;
            or_ending_here.insert(arr[i]);
            ans.insert(arr[i]);
            int t = arr[i];
            for(auto &a: or_ending_prev)
            {
                int x = t | a;
                or_ending_here.insert(x);
                ans.insert(x);
            }

            or_ending_prev = or_ending_here;
        }
        return ans.size();
    }
};