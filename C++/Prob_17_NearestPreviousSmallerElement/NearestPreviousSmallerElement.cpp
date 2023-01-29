#include<bits/stdc++.h>
using namespace std;

// Input :
// enter no of test cases: 
// enter size of the vector/array:
// input array for ex: 1 4 2 6 7  -> acording to size

vector<int> findNearestSmallerElement(vector<int> arr, int n)
{
	stack<int> s;
	vector<int> res;

	for(auto a:arr)
	{
		cout<<a;
		cout<<"\n";
		//while(!s.empty() && s.top()<=a)
		while(!s.empty() && s.top()>=a)
		{
			s.pop();
		}
		if(s.empty())
		{
			res.push_back(-1);
		}
		else{
			res.push_back(s.top());
		}

		s.push(a);
	}

	return res;
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
		result = findNearestSmallerElement(arr,n);
		//cout<<"\n";
		for(auto a:result)
		{
			cout<<a<<" ";
		}
	}
}