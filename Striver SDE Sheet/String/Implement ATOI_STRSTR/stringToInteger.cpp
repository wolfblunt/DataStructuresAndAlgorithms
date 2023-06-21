// String to Integer (atoi)

#include <bits/stdc++.h> 
int atoi(string s) {
    int i=0;
    int n = s.size();
    bool isNegative = false;
    while(i<n && s[i]==' ')
    {
        i++;
    }

    if(i<n && (s[i] == '+' || s[i] == '-'))
    {
        if(s[i] == '-')
        {
            isNegative = true;
        }
        i++;
    }

    double stoi = 0;
    for(; i<n;i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            int temp = s[i] - '0';
            stoi = stoi*10 + temp;
        }
    }

    if(isNegative==true)
    {
        stoi = -stoi;
    }

    if(stoi < INT_MIN)
    {
        stoi = INT_MIN;
    }

    if(stoi > INT_MAX)
    {
        stoi = INT_MAX;
    }

    return stoi;
}