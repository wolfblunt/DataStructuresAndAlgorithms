// Next Greater Element in Circular Array - O(2*n)

#include<bits/stdc++.h>
using namespace std;

vector<int> nextLargerElementInCircularArray(vector<int> &arr) {
    stack<int> st;
    int n = arr.size();
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        arr.push_back(arr[i]);
    }
    
    for(int i=2*n-1;i>=0;i--)
    {
        while(!st.empty() && arr[i%n] >= st.top())
        {
            st.pop();
        }
        
        if(i<n)
        {
            if(!st.empty())
            {
                ans.push_back(st.top());
            }
            else
            {
                ans.push_back(-1);
            }
        }
        
        st.push(arr[i%n]);
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
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
		result = nextLargerElementInCircularArray(arr,n);
		//cout<<"\n";
		for(auto a:result)
		{
			cout<<a<<" ";
		}
	}
}