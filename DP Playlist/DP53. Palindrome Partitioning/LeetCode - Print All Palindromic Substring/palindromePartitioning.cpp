// Palindrome Partitioning -- Print all Palindrome Partitions

class Solution {
public:
    bool isPalindrome(string &s, int l, int r)
    {
        while(l<=r)
        {
            if(s[l++]!=s[r--])
            {
                return false;
            }
        }
        return true;
    }

    void helperFunc(string &s, int index, vector<string> &temp, vector<vector<string>> &result)
    {
        if(index==s.size())
        {
            result.push_back(temp);
            return;
        }

        for(int i=index;i<s.size();i++)
        {
            if(isPalindrome(s, index, i))
            {
                temp.push_back(s.substr(index, i-index+1));
                helperFunc(s, i+1, temp, result);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> result;
        helperFunc(s, 0, temp,  result);
        return result;
    }
};