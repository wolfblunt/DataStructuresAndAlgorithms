// Phone directory
// https://practice.geeksforgeeks.org/problems/phone-directory4628/1

#include <bits/stdc++.h>
using namespace std;


class TrieNode
{
    public:
    TrieNode* children[26];
    bool flag;
    
    bool containsKey(char ch)
    {
        return (children[ch-'a']!=NULL);
    }
    
    TrieNode* get(char ch)
    {
        return children[ch-'a'];
    }
    
    void put(char ch, TrieNode* node)
    {
        children[ch - 'a'] = node;
    }
    
    bool setEnd()
    {
        flag = true;
        return flag;
    }
    
    bool isEnd()
    {
        return flag;
    }
};


class Trie
{
    private:
    TrieNode* root;
    public:
    Trie()
    {
        root = new TrieNode();
    }
    
    void insert(string &word)
    {
        TrieNode* node = root;
        
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i], new TrieNode());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    void dfs(string addressPrefix, TrieNode* current, vector<string> &result)
    {
        if(current->isEnd())
        {
            result.push_back(addressPrefix);
        }
        
        for(char ch='a'; ch<='z';ch++)
        {
            if(current->containsKey(ch))
            {
                addressPrefix+=ch;
                dfs(addressPrefix, current->get(ch), result);
                addressPrefix.pop_back();
            }
        }
    }
    
    vector<string> findContacts(string addressPrefix)
    {
        TrieNode* current = root;
        vector<string> result;
        // cout<<"addressPrefix : "<<addressPrefix<<endl;
        for(int i=0;i<addressPrefix.length();i++)
        {
            if(!current->containsKey(addressPrefix[i]))
            {
                return {"0"};
            }
            else
            {
                current = current->get(addressPrefix[i]);
            }
        }
        dfs(addressPrefix, current, result);
        return result;
    }
};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie t;
        for(int i=0;i<n;i++)
        {
            t.insert(contact[i]);
        }
        
        vector<vector<string>> solution;
        string prefix = "";
        for(int i=0;i<s.length();i++)
        {
            prefix+=s[i];
            solution.push_back(t.findContacts(prefix));
        }
        return solution;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}

/* Input : 
1
3
geeikistest geeksforgeeks geeksfortest
geeips

Output :
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest
0
0
*/