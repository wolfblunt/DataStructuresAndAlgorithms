#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> arr = {1, -1, 3, 2, -7, -5, 11, 6 };
	int n = arr.size();
	int low = -1;
	int pivot = 0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>pivot)
		{
			low++;
			swap(arr[i], arr[low]);
		}
	}

	for(auto& it:arr)
	{
		cout<<it<<" ";
	}
}