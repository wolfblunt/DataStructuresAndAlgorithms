// Palindrome Partitioning

class Solution {
public:
    bool isPalindrome(string &s, int start, int end)
    {
        while(start <= end)
        {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }

    void dfs(string&s, int index, vector<string> &temp, vector<vector<string>> &result)
    {
        int n = s.size();
        if(index == s.size())
        {
            result.push_back(temp);
            return;
        }
        for(int i = index; i<n; i++)
        {
            if(isPalindrome(s, index, i))
            {
                temp.push_back(s.substr(index, i - index + 1));
                dfs(s, i+1, temp, result);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> result;
        vector<string> temp;
        if(s.length()==0)
            return result;
        
        dfs(s, 0, temp, result);
        return result;
    }
};