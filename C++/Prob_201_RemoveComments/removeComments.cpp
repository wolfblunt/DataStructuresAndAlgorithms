// Remove Comments

class Solution {
public:
    vector<string> removeComments(vector<string>& source) 
    {
        string s = "";
        vector<string> ans;
        bool mode = false;
        for(auto a: source)
        {
            int n = a.length();
            for(int i=0;i<n;i++)
            {
                if(mode)
                {
                    if(a[i] == '*' && i < n-1 && a[i+1] == '/')
                    {
                        mode = false;
                        i++;
                    }
                }
                else
                {
                    if(a[i] == '/' && i < n-1 && a[i+1] == '/')
                    {
                        break;
                    }
                    else if(a[i] == '/' && i < n-1 && a[i+1] == '*')
                    {
                        mode = true;
                        i++;
                    }
                    else
                    {
                        s.push_back(a[i]);
                    }
                }
            }

            if(mode == false && s.length() > 0)
            {
                ans.push_back(s);
                s = "";
            }
        }

        return ans;
    }
};