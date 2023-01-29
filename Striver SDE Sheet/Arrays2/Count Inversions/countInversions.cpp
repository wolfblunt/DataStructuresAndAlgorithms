// Count Inversions

#include <bits/stdc++.h> 

long long merge(long long *arr, int p, int q, int r)
{
    long long inversion = 0;
    int n1 = q-p+1;
    int n2 = r-q;
    vector<int> a(n1);
    vector<int> b(n2);
    for(int i=0;i<n1;i++)
    {
        a[i] = arr[p+i];
    }
    for(int j=0;j<n2;j++)
    {
        b[j] = arr[q+1+j];
    }
    int i=0,j=0,k=p;
    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j])
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = b[j];
            inversion+=n1-i;
            j++;
            k++;
        }
    }
    
    while(i<n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    
    while(j<n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }
    
    return inversion;
}

long long mergeSort(long long *arr, int p, int r)
{
    long long inversion = 0;
    if(p<r)
    {
        int q = (p+r)/2;
        inversion += mergeSort(arr, p, q);
        inversion += mergeSort(arr, q+1, r);
        inversion += merge(arr, p, q, r);
    }
    return inversion;
}

long long getInversions(long long *arr, int n){
    long long inversion;
    inversion = mergeSort(arr, 0, n-1);
    return inversion;
}