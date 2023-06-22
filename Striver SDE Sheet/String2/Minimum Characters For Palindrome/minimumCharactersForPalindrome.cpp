// Minimum Characters For Palindrome


#include<bits/stdc++.h>
int lcpFunc(string a, int m, int* lcp)
{
    int len = 0;
    int j = 1;
    lcp[len] = 0;
    while(j<m)
    {
        if(a[j] == a[len])
        {
            len++;
            lcp[j] = len;
            j++;
        }
        else
        {
            if(len!=0)
            {
                len = lcp[len-1];
            }
            else
            {
                lcp[j] = 0;
                j++;
            }
        }
    }
    
    return lcp[m-1];
}


int minCharsforPalindrome(string A) {
	string B = A;
    reverse(B.begin(), B.end());
    B = A+"#"+B;
    int m = B.size();
    int lcp[m];
    int l = lcpFunc(B, m, lcp);
    return A.size() - l;
}
