// Geeks And The String

#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    string removePair(string s)
    {
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else if(st.top()==s[i])
            {
                st.pop();
                continue;
            }
            else if(st.top()!=s[i])
            {
                st.push(s[i]);
            }
        }
        
        string ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        if(ans.length()==0)
            return "-1";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}