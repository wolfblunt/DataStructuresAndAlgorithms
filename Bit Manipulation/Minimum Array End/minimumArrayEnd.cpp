// Minimum Array End - O(64)

class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        vector<int> xBit(64,0);
        vector<int> nBit(64,0);

        for(int i=0;i<32;i++)
        {
            xBit[i] = (x>>i) & 1;
            nBit[i] = (n>>i) & 1;
        }

        int i = 0;
        int j = 0;

        while(i<64)
        {
            if(xBit[i] == 1)
            {
                i++;
                continue;
            }
            xBit[i++] = nBit[j++];
        }

        long long ans = 0;
        for(int k=0;k<64;k++)
        {
            ans += xBit[k] * (1ll<<k);
        }

        return ans;
    }
};