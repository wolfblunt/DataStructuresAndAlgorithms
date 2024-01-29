// Remove K Digits

class Solution {
  public:
    string removeKdigits(string S, int K) {
        stack<char> st;
        for(auto a: S)
        {
            while(!st.empty() && K && st.top() > a)
            {
                st.pop();
                K--;
            }
            
            if(a != '0' || !st.empty())
            {
                st.push(a);
            }
        }
        
        while(!st.empty() && K)
        {
            st.pop();
            K--;
        }
        string ans = "";
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans=="" ? "0" : ans;
    }
};