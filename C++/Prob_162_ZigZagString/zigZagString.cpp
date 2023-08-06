// Zig-Zag String

#include <bits/stdc++.h> 
string zigZagString(string str, int n, int m) {
    if (m == 1)
    {     
        return str;
    }  
    string arr[m];
    bool down = true;
    int row = 0;
    for(int i=0;i<n;i++)
    {
        arr[row].push_back(str[i]);
        if(row == m-1)
        {
            down = false;
        }
        else if(row == 0)
        {
            down = true;
        }

        if(down == true)
        {
            row++;
        }
        else
        {
            row--;
        }
    }

    string ans="";
    for(int i=0;i<m;i++)
    {
        ans += arr[i];
    }
    return ans;
}