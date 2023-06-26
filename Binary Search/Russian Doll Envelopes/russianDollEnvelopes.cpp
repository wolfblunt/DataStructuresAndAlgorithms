// Russian Doll Envelopes -- SImilar to Longest Inccreasing Subsequence using Binary Search
// Time : O(nlogn)

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if(a[0] == b[0])
        {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int> temp;

        for(int i=0;i<n;i++)
        {
            int val = envelopes[i][1];
            int index = lower_bound(temp.begin(), temp.end(), val) - temp.begin();
            if(index >= temp.size())
            {
                temp.push_back(val);
            }
            else
            {
                temp[index] = val;
            }
        }

        return temp.size();
    }
};