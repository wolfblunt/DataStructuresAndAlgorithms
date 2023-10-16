// Remove Comments

string removeComments (string a)
{
    string s = "";
    bool mode = false;
    
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
                i+=2;
                while(i<n-1)
                {
                    if(int(a[i])==92 && a[i+1] == 'n')  // 92 - '\'
                    {
                        i++;
                        break;
                    }
                    i++;
                }
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

    return s;
}