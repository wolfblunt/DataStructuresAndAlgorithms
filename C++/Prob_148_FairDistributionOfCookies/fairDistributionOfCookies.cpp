// Fair Distribution of Cookies

class Solution {
public:
    void helper(int start, vector<int>& cookies, vector<int>& distribute, int k, int &ans)
    {
        int n = cookies.size();

        if(start==n)
        {
            int maxi = INT_MIN;
            for(int i=0;i<k;i++)
            {
                maxi = max(distribute[i], maxi);
            }
            ans = min(ans, maxi);
            return;
        }

        for(int i=0;i<k;i++)
        {
            distribute[i] += cookies[start];  // take
            helper(start+1, cookies, distribute, k, ans);
            distribute[i] -= cookies[start];  // backtrack
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int ans = INT_MAX;
        vector<int> distribute(k, 0);
        helper(0, cookies, distribute, k, ans);
        return ans;
    }
};