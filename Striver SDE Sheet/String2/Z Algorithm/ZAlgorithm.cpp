// Z Algorithm - Linear time pattern searching Algorithm : time - O(n+m)
// reference: https://cp-algorithms.com/string/z-function.html#efficient-algorithm-to-compute-the-z-function

vector<int> z_function(string s)
{
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++)
    {
        if(i < r) 
        {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) 
        {
            z[i]++;
        }
        if(i + z[i] > r) 
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

vector <int> search(string pat, string txt)
{
    int n = txt.size(), m = pat.size();
    string text = pat + '$' + txt;
    vector<int> zValues = z_function(text);
    
    vector<int> ans;
    for (int i = 0; i < text.size(); i++) 
    {
        if (zValues[i] == m)
          ans.push_back(i - m); // for 0 based indexing use i - m - 1
    }
    
    return ans;
}