// Column name from a given column number

class Solution{
    public:
    string colName (long long int n)
    {
        vector<char> alphabets(26);
        alphabets[0] = 'A';
        for(int i=1;i<26;i++)
        {
            alphabets[i] = char(int(alphabets[i-1]+1));
        }
        
        string ans="";
        while(n>0)
        {
            long long rem = (n-1)%26;
            ans = alphabets[int(rem)] + ans;
            n = (n-1)/26;
        }
        
        return ans;
    }
};