// Total Cost to Hire K Workers

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        int n = costs.size();
        int i = 0;
        int j = n - 1;
        long long answer = 0;
        while(k--)
        {
            while(pq1.size() < candidates && i<=j)
            {
                pq1.push(costs[i++]);
            }

            while(pq2.size() < candidates && i<=j)
            {
                pq2.push(costs[j--]);
            }

            int c1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int c2 = pq2.size() > 0 ? pq2.top() : INT_MAX;

            if(c1 <= c2)
            {
                answer += c1;
                pq1.pop();
            }
            else
            {
                answer += c2;
                pq2.pop();
            }
        }

        return answer;
    }
};