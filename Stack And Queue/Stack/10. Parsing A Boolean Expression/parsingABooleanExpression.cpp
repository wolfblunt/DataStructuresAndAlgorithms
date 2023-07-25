// Parsing A Boolean Expression

class Solution {
public:
    bool parse_and(vector<int>& res)
    {
        int mask = res[0];
        for(int i=1;i<res.size();i++)
        {
            mask &= res[i];
        }
        return mask;
    }

    bool parse_or(vector<int>& res)
    {
        int mask = res[0];
        for(int i=1;i<res.size();i++)
        {
            mask |= res[i];
        }
        return mask;
    }

    bool parseBoolExpr(string expression) {
        int n = expression.size();
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if(expression[i] == ',')
            {
                continue;
            }
            if(expression[i] == ')')
            {
                vector<int> res;
                while(st.top()!='&' && st.top()!='|' && st.top()!='!')
                {
                    char c = st.top();
                    st.pop();
                    if(c=='t')
                    {
                        res.push_back(1);
                    }
                    if(c=='f')
                    {
                        res.push_back(0);
                    }
                }
                char c = st.top();
                st.pop();
                if(c=='&')
                {
                    if(parse_and(res))
                    {
                        st.push('t');
                    }
                    else
                    {
                        st.push('f');
                    }
                }
                else if(c=='|')
                {
                    if(parse_or(res))
                    {
                        st.push('t');
                    }
                    else
                    {
                        st.push('f');
                    }
                }
                else if(c=='!')
                {
                    if(res[0]==0)
                    {
                        st.push('t');
                    }
                    else
                    {
                        st.push('f');
                    }
                }
            }
            else
            {
                st.push(expression[i]);
            }
        }
        return (st.top() == 't');
    }
};