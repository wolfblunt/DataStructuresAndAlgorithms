// Strobogrammatic Number
#include <bits/stdc++.h> 

vector<string> helper(int n, int length)
{
    vector<string> result;
    if(n==0)
    {
        result.push_back("");
        return result;
    }
    if(n==1)
    {
        result.push_back("0");
        result.push_back("1");
        result.push_back("8");
        return result;
    }
    if(n==2 && length==2)
    {
        result.push_back("11");
        result.push_back("69");
        result.push_back("88");
        result.push_back("96");
        return result;
    }
    vector<string> middleNumbers = helper(n-2, n);
    for(string middle: middleNumbers)
    {
        if(n!=length)
        {
            result.push_back("0"+middle+"0");
        }
        result.push_back("1"+middle+"1");
        result.push_back("8"+middle+"8");
        result.push_back("6"+middle+"9");
        result.push_back("9"+middle+"6");
    }
    return result;
}

vector<string> findStrobogrammatic(int n) {
	vector<string> result = helper(n,n);
    return result;
}