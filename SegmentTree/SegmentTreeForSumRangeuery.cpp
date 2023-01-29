#include <bits/stdc++.h>
using namespace std;
#define int long long int
// int A[100005], seg[4*100005];
vector<int> A;

void build(int idx, int low, int high, vector<int>&seg)
{
    if(low == high)
    {
        seg[idx] = A[low];
        // cout<<idx<<": "<<A[low]<<" ";
    }
    else
    {
        int mid = (low + high) / 2;
        build(2*idx+1, low, mid, seg);
        build(2*idx+2, mid+1, high, seg);
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
        // cout<<idx<<": "<<seg[idx]<<" ";
    }
}

int query(int idx, int low, int high, int l, int r, vector<int>& seg)
{
    if(r < low or high < l)
    {
        return 0;
    }
    if(l <= low and high <= r)
    {
        return seg[idx];
    }
    int mid = (low + high) / 2;
    int p1 = query(2*idx+1, low, mid, l, r, seg);
    int p2 = query(2*idx+2, mid+1, high, l, r, seg);
    return p1 + p2;
}

void update(int idx, int low, int high, int idx1, int val, vector<int>&seg)
{
    if(low == high)
    {
        A[idx1] = val;
        seg[idx] = val;
    }
    else
    {
        int mid = (low + high) / 2;
        if(low <= idx1 and idx1 <= mid)
        {
            update(2*idx+1, low, mid, idx1, val, seg);
        }
        else
        {
            update(2*idx+2, mid+1, high, idx1, val, seg);
        }
        // cout<<(2*idx+1)<<" : "<<seg[2*idx+1]<<endl;
        // cout<<(2*idx+2)<<" : "<<seg[2*idx+2]<<endl;
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
        // cout<<idx<<" : "<<seg[idx]<<endl;
    }
}

int32_t main()
{
	int n,q;
	cin>>n>>q;
	A.resize(n);
	vector<int>seg;
	seg.resize(4*n);
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	vector<int> v;
	build(0,0,n-1, seg);
	while(q--)
	{
		int choice;
		int l,r;
		cin>>choice>>l>>r;
		if(choice==1)
		{
			update(0, 0, n-1, l-1, r, seg);
		}
		if(choice==2)
		{
			v.push_back(query(0,0,n-1,l-1,r-1, seg));
		}
	}
	//cout<<endl;
	for(auto a: v)
	{
		cout<<a<<endl;
	}
	return 0;
}


