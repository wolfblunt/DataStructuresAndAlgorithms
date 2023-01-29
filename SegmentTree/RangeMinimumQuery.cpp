//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends

void buildSegmentTree(int index, int low, int high, int* segmentTree, int arr[])
{
    if(low==high)
    {
        segmentTree[index] = arr[low];
        return;
    }
    int mid = (low+high)/2;
    buildSegmentTree(2*index+1, low, mid, segmentTree, arr);
    buildSegmentTree(2*index+2, mid+1, high, segmentTree, arr);
    segmentTree[index] = min(segmentTree[2*index+1], segmentTree[2*index+2]);
}


/* The functions which 
builds the segment tree */
int *constructST(int arr[],int n)
{
    int *segmentTree = new int[4*n+1];
    // segmentTree.resize(4*n);
    buildSegmentTree(0, 0, n-1, segmentTree, arr);
    return segmentTree;
}

int RMQFind(int index, int low, int high, int a, int b, int st[])
{
    if(a>high || b<low)
    {
        return INT_MAX;
    }
    if(a<=low && b>=high)
    {
        return st[index];
    }
    int mid = (low+high)/2;
    int p = RMQFind(2*index+1, low, mid, a,b,st);
    int q = RMQFind(2*index+2, mid+1, high,a,b,st);
    return min(p,q);
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b)
{
    return RMQFind(0,0, n-1,a,b,st);
}