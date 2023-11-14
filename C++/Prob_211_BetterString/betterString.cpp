// Better String - O( max( str1.length, str2.length ) )

class Solution {
  public:
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
    
    string betterString(string str1, string str2) {
        int count1 = substringCount(str1);
        int count2 = substringCount(str2);
        if(count1 < count2)
        {
            return str2;
        }
        
        return str1;
    }
};