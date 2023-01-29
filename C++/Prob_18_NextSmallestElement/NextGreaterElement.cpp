#include<bits/stdc++.h>
using namespace std;

vector<int> findNextGreaterElement(vector<int> arr, int n)
{
	stack<int> s;
	vector<int> result;
	for(int i=n-1;i>=0;i--)
	{
		while(!s.empty() && arr[i]>=s.top())
		{
			s.pop();
		}
		if(s.empty())
		{
			result.push_back(-1);
		}
		else{
			result.push_back(s.top());
		}
		s.push(arr[i]);
	}
	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	cout<<"Enter no of test cases: ";
	int t;
	cin>>t;
	while(t--)
	{
		cout<<"\nEnter size of the array : ";
		int n;
		cin>>n;
		vector<int> arr;
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			arr.push_back(temp);
		}

		vector<int> result;
		result = findNextGreaterElement(arr,n);
		//cout<<"\n";
		for(auto a:result)
		{
			cout<<a<<" ";
		}
	}
}