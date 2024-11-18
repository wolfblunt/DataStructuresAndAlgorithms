// Shortest Subarray with Sum at Least K - O(N∗Log(N))

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();


class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq; // min-heap
        long long n = nums.size();

        long long sum = 0;
        long long len = 1e18;

        for(long long i=0;i<n;i++)
        {
            sum += (long long)nums[i];
            if(sum >= k)
            {
                len = min(len, i+1);
            }

            while(!pq.empty() && sum-pq.top().first >= k)
            {
                auto ele = pq.top();
                len = min(len, i-ele.second);
                pq.pop();
            }
            pq.push({sum, i});
        }


        return len == 1e18 ? -1 : (int)len;
    }
};