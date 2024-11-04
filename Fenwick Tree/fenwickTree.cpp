// Fenwick Tree Implementation - O(nlogn)

#include<bits/stdc++.h>  
using namespace std;

int n;
vector<int> bit;

void update(int idx, int val) // O(logn)
{
	while(idx <= n)
	{
		bit[idx] += val;
		idx += idx & (-idx);
	}
}

int query(int idx)  // O(logn)
{
	int ans = 0;
	while(idx > 0)
	{
		ans += bit[idx];
		idx -= idx & (-idx);  // subtracting the most signiicant bit
	}

	return ans;
}


int32_t main()
{
	cin>>n; // no. of elements in array
	bit = vector<int>(n+1);
	vector<int> a(n+1);

	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		update(i, a[i]);
	}

	int q;
	cin>>q;  // no of queries

	while(q--)
	{
		int c;
		cin>>c;
		if(c == 1)  // query between range and give sum of the range
		{
			int l,r; // l to r should be one based index for fenwick tree
			cin>>l>>r;
			int ans = query(r) - query(l-1);  // [0...r] - [0...l]
			cout<<ans<<endl;
		}
		else if(c == 2) // update the value of the index with val
		{
			int index, val;
			cin>>index>>val;
			update(index, -a[index]);
			a[index] = val;
			update(index, val);
		}
	}
}