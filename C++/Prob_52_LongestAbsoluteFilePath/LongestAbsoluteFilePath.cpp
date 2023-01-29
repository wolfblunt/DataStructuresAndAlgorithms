class Solution {
public:
    int lengthLongestPath(string input) {
        stack<int> s;
        string temp;
        bool file=0;
        int n = input.size();
        int ans = 0;
        int level = 1;
        
        for(int i=0;i<n;i++)
        {
            char x = input[i];
            if(x=='.')
            {
                file=1;
            }
            if(x=='\n' || x=='\t')
            {
                while(s.size()>=level)
                {
                    s.pop();
                }
                if(s.size()>0)
                {
                    s.push(s.top() + temp.size());
                }
                else
                {
                    s.push(temp.size());
                }
                temp.clear();
                if(file)
                {
                    ans = max(ans, (s.top()+(int)(s.size()-1)));
                }
                file=0;
                level = 0;
                while(i<n && input[i]=='\n' || input[i]=='\t')
                {
                    i++;
                    level++;
                }
                i--;
                //temp.clear();
            }
            else
            {
                temp.push_back(x);
            }
        }
        
        while(s.size()>=level)
        {
            s.pop();
        }
        if(s.size()>0)
        {
            s.push(s.top() + temp.size());
        }
        else
        {
            s.push(temp.size());
        }
        if(file)
        {
            ans = max(ans, s.top()+(int)(s.size()-1));
        }
        return ans;
    }
};