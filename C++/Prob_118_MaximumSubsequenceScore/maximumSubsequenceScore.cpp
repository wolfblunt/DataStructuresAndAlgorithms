// Maximum Subsequence Score

class Solution {
public: 
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        vector<pair<int,int>> v;
        int n = nums2.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({nums2[i], nums1[i]});
        }

        sort(v.begin(), v.end(), greater<pair<int,int>>());  // Sorting in Descending Order

        priority_queue<int, vector<int>, greater<int>> pq;   // Min Heap
        long long result=0;
        long long sum = 0;
        for(int i=0;i<k-1;i++)
        {
            pq.push(v[i].second);
            sum+=v[i].second;
        }

        for(int i=k-1;i<n;i++)
        {
            if(pq.size() < k)
            {
                pq.push(v[i].second);
                sum+=v[i].second;
                result = max(result, sum*v[i].first);
            }
            else if(pq.size() >= k && pq.top() < v[i].second)
            {
                sum-=pq.top();
                pq.pop();
                pq.push(v[i].second);
                sum+=v[i].second;
                result = max(result, sum*v[i].first);
            }
        }
        return result;
    }
};