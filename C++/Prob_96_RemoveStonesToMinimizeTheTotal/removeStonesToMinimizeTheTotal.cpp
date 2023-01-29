// Remove Stones to Minimize the Total
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        for(int i=0;i<k;i++)
        {
            int t = pq.top();
            pq.pop();
            t=t-floor(t/2);
            pq.push(t);
        }
        int sum=0;
        int n = pq.size();
        for(int i=0;i<n;i++)
        {
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};