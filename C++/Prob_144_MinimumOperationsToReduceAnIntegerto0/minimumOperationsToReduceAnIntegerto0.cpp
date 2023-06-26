// Minimum Operations to Reduce an Integer to 0

class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        while(n>0)
        {
            if((n&1) == 1)
            {
                ans++;
                n = n/2;
                if((n&1) == 1)
                {
                    n++;
                }
            }
            else
            {
                n = n/2;
            }
        }

        return ans;
    }
};