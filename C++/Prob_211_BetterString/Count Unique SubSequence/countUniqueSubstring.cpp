// Count Unique Substring - O(n)

int substringCount(string &str)
{
    vector<int> alpha(26,-1);
    int count = 1;
    int n = str.length();
    for(int i=0;i<n;i++)
    {
        if(alpha[str[i]-'a'] == -1)
        {
            alpha[str[i]-'a'] = count;
            count = count*2;
        }
        else if(alpha[str[i]-'a'] != -1)
        {
            int temp = alpha[str[i]-'a'];
            alpha[str[i]-'a'] = count;
            count = count*2 - temp;
        }
    }
    
    return count;
}