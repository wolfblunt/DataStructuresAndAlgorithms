// Find Building Where Alice and Bob Can Meet

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    vector<int>seg;
    void build(int idx, int low, int high, vector<int>&heights)
    {
        if(low == high)
        {
            seg[idx] = low;
        }
        else
        {
            int mid = (low + high) / 2;
            build(2*idx+1, low, mid, heights);
            build(2*idx+2, mid+1, high, heights);
            seg[idx] = heights[seg[2*idx+1]] >= heights[seg[2*idx+2]] ? seg[2*idx+1] : seg[2*idx+2];
        }
    }

    int query(int idx, int low, int high, int l, int r, vector<int>& heights)
    {
        if(r < low or high < l)
        {
            return INT_MIN;
        }
        if(l <= low and high <= r)
        {
            return seg[idx];
        }
        int mid = (low + high) / 2;
        int left_max = query(2*idx+1, low, mid, l, r, heights);
        int right_max = query(2*idx+2, mid+1, high, l, r, heights);
        if(left_max == INT_MIN)
        {
            return right_max;
        }
        if(right_max == INT_MIN)
        {
            return left_max;
        }
        return heights[left_max] >= heights[right_max] ? left_max : right_max;
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = heights.size();
	    seg.resize(4*n);
        build(0,0,n-1, heights);

        for(auto a: queries)
        {
            int alice = min(a[0], a[1]);
            int bob = max(a[0], a[1]);

            if(alice == bob || heights[alice] < heights[bob])
            {
                ans.push_back(bob);
                continue;
            }

            int low = bob;
            int high = n-1;
            int res = INT_MAX;

            while(low <= high)
            {
                int mid = low + (high-low)/2;
                int range_max_query = query(0,0,n-1,low,mid,heights);

                if(heights[range_max_query] > heights[alice])
                {
                    high = mid-1;
                    res = min(res, range_max_query);
                }
                else
                {
                    low = mid+1;
                }
            }

            if(res == INT_MAX)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(res);
            }
        }

        return ans;
    }
};