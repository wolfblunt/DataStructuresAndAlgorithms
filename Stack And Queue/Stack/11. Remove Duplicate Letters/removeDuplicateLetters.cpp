// Remove Duplicate Letters

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        vector<int> lastIndex(26, 0);
        vector<int> flag(26, 0);

        for(int i=0;i<n;i++)
        {
            lastIndex[s[i] - 'a'] = i;
        }

        stack<int> st;
        for(int i=0;i<n;i++)
        {
            int curr = s[i] - 'a';
            if(flag[curr])
            {
                continue;
            }
            while(!st.empty() && st.top() > curr && i < lastIndex[st.top()])
            {
                flag[st.top()] = 0;
                st.pop();
            }

            st.push(curr);
            flag[curr] = 1;
        }

        string ans = "";

        while(!st.empty())
        {
            ans += char(st.top() + 'a');
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};