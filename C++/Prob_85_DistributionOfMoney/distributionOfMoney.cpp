#include <bits/stdc++.h> 
int minTransactions(int k, vector < int > & arr) {
    int sum=0;
    if(arr.size()==1)
    {
        return 0;
    }
    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];
    }
    int average = sum/(arr.size());
    if(sum%average!=0)
    {
        return -1;
    }
    int count=0;
    for(int i=0;i<arr.size();i++)
    {
        if((arr[i]-average)%k!=0)
        {
            return -1;
        }
        if(arr[i]>average)
        {
            int d = arr[i];
            while(d>average)
            {
                count++;
                d = d-k;
            }
        }
    }
    return count;
}