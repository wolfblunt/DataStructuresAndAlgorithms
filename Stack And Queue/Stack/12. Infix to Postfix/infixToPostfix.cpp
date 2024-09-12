// Infix to Postfix - O(n)

class Solution {
  public:
    int priority(char a)
    {
        if(a == '^')
        {
            return 3;
        }
        else if(a == '*' || a == '/')
        {
            return 2;
        }
        else if(a == '+' || a == '-')
        {
            return 1;
        }
        return -1;
    }
    
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        string postFix = "";
        int n = s.length();
        stack<char> st;
        for(int i=0;i<n; i++)
        {
            if((s[i] >= 'a' && s[i] <='z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
            {
                postFix+=s[i];
            }
            else if(s[i] == '(')
            {
                st.push(s[i]);
            }
            else if(s[i] == ')')
            {
                while(!st.empty() && st.top() != '(')
                {
                    postFix+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while(!st.empty() && priority(st.top()) >= priority(s[i]))
                {
                    postFix+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        
        while(!st.empty())
        {
            postFix+=st.top();
            st.pop();
        }
        
        return postFix;
    }
};