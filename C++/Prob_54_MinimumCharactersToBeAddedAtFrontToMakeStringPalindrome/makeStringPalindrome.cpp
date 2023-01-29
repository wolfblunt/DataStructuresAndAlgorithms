// Minimum characters to be added at front to make string palindrome

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Normal Approach

    // int minChar(string str){
    //     int left=0;
    //     int right = str.length()-1;
    //     int temp = right;
    //     int count=0;
    //     while(left<right)
    //     {
    //         if(str[left]==str[right])
    //         {
    //             left++;
    //             right--;
    //         }
    //         else{
    //             count++;
    //             left = 0;
    //             right = --temp;
    //         }
    //     }
        
    //     return count;
    // }
    
    // Using LPS (longest length of largest prefix that matches suffix.) -> used in KMP algo (String Matching)

    int lpsFunc(string st, int n, int* lps)
    {
        lps[0] = 0;
        int len = 0;
        int i=1;
        while(i<n)
        {
            if(st[i]==st[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0)
                {
                    len = lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps[i-1];
    }
    
    int minChar(string str){
        string ss = str;
        reverse(ss.begin(), ss.end());
        string f = str+"#"+ss;
        int m = f.length();
        int lps[m];
        int finVal = lpsFunc(f, m, lps);
        int res = str.length() - finVal;
        return res;
    }
};


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}