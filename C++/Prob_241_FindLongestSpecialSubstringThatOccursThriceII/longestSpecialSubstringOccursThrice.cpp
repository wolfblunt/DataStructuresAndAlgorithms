// Find Longest Special Substring That Occurs Thrice II

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    int &getMinimum(int &a, int &b, int &c)
    {
        if(a<=b && a<=c)
        {
            return a;
        }
        if(b<=a && b<=c)
        {
            return b;
        }
        return c;
    }

    int maximumLength(string s) {
        int n = s.length();
        vector<vector<int>> top3freq(26, vector<int>(3, -1));
        char lastSeen = '*';
        int windowLength = 1;

        for(auto a: s)
        {
            int index = a-'a';
            windowLength = lastSeen == a ? windowLength+1 : 1;
            lastSeen = a;
            int &minimum = getMinimum(top3freq[index][0], top3freq[index][1], top3freq[index][2]);
            if(windowLength > minimum)
            {
                minimum =  windowLength;
            }
        }

        int max3Length = -1;

        for(int i=0;i<26;i++)
        {
            max3Length = max(max3Length, min(top3freq[i][0], min(top3freq[i][1], top3freq[i][2])));
        }

        return max3Length;
    }
};