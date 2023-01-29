// Container With Most Water

#include<bits/stdc++.h>
using namespace std;

long long maxArea(long long arr[], int len)
{
    int left=0;
    int right = len-1;
    int max_area = INT_MIN;
    while(left<=right)
    {
        int area=0;
        if(arr[left]>=arr[right])
        {
            area = (right-left)*arr[right];
            max_area = max(max_area, area);
            right--;
        }
        else
        {
            area = (right-left)*arr[left];
            max_area = max(max_area, area);
            left++;
        }
    }
    return max_area;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}