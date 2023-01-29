#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubstring(string& text1, string& text2, int index1, int index2, vector<vector<int>> &dp)
    {
        if(index1<0 || index2<0)
        {
            return 0;
        }
        if(dp[index1][index2] != -1)
        {
            return dp[index1][index2];
        }
        
        if(text1[index1]==text2[index2])
        {
            return dp[index1][index2] = 1+longestSubstring(text1, text2, index1-1, index2-1, dp);
            
        }
        int c1 = longestSubstring(text1, text2, index1-1, index2, dp);
        int c2 = longestSubstring(text1, text2, index1, index2-1, dp);
        return dp[index1][index2] = 0+max(c1,c2);
    }

    

    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        int answer =  longestSubstring(text1, text2, m-1, n-1, dp);
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return answer;
    }
};

int main() {

    string s1= "abcde";
    string s2= "bdgek";
    Solution obj;
    int len = obj.longestCommonSubsequence(s1,s2);                             
    cout<<"The Length of Longest Common Subsequence is "<<len;
    return 0;
}