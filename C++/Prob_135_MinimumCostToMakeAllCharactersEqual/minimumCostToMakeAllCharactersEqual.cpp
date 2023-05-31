// Minimum Cost to Make All Characters Equal

class Solution {
public:
    long long minimumCost(string s) {
        long long ans = 0;
        int n = s.size();
        for(int i=1;i<n;i++)
        {
            if(s[i] != s[i-1])
            {
                ans += min(i,n-i); // Key Observation
                                    //Think Greedy 
            }
        }return ans;
    }
};