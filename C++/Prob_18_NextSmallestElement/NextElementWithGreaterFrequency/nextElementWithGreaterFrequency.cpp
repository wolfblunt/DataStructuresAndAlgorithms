// Next element with greater frequency - O(N)

class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> um;
        for(auto &a: arr)
        {
            um[a]++;
        }
        
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && um[st.top()] <= um[arr[i]])
            {
                st.pop();
            }
            
            if(!st.empty())
            {
                ans[i] = st.top();
            }
            
            st.push(arr[i]);
        }
        
        return ans;
    }
};