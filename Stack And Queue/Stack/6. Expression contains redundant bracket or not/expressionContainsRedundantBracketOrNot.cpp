// Expression contains redundant bracket or not

#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    int n = s.length();
    stack<char> st;
    for(int i=0;i<n;i++)
    {
        if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            st.push(s[i]);
        }

        if(s[i] == ')')
        {
            bool isRedundant = true;
            while(st.top()!='(')
            {
                if(!st.empty() && (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'))
                {
                    isRedundant = false;
                }
                st.pop();
            }

            if(isRedundant == true)
            {
                return true;
            }

            st.pop();
        }
    }

    return false;
}