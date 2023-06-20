// Maximum Sum Combination

class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &A, vector<int> &B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        vector<int> ans;
        priority_queue<pair<int,pair<int, int>>> pq; // {sum, {A_index, B_index}}
        set<pair<int, int>> s;
        
        pq.push({A[n-1] + B[n-1], {n-1, n-1}});
        s.insert({n-1, n-1});
        
        while(k--)
        {
            int a = pq.top().second.first;
            int b = pq.top().second.second;
            
            ans.push_back(pq.top().first);
            pq.pop();
            
            if(s.find({a-1, b}) == s.end())
            {
                pq.push({A[a-1] + B[b], {a-1, b}});
                s.insert({a-1, b});
            }
            
            if(s.find({a, b-1}) == s.end())
            {
                pq.push({A[a] + B[b-1], {a, b-1}});
                s.insert({a, b-1});
            }
        }
        
        return ans;
    }
};