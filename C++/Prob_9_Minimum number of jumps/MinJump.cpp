#include<iostream>
#include<vector>
using namespace std;

int minJump(vector<int> a, int n)
{
	int maxR = a[0];
	int jump = 1;
	int step = a[0];

	if(a[0]==0)
	{
		return -1;
	}
	if(n==1)
	{
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		if(i==n-1)
		{
			return jump;
		}
		maxR = max(maxR, i+a[i]);
		step--;
		if(step==0)
		{
			jump++;
			if(maxR<=i)
			{
				return -1;
			}
			step = maxR-i;
		}
	}

	return 0;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> a;
		for(int i=0;i<n;i++)
		{
			int t;
			cin>>t;
			a.push_back(t);
		}
		for(auto it:a)
		{
			cout<<it<<" ";
		}
		int jump = minJump(a,n-1);
		cout<<"\n";
		cout<<jump;
	}
}