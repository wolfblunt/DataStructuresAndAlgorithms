#include<iostream>
using namespace std;

int main()
{
	int arr[16] = {10,9,8,7,6,5,5,4,3,2,1,5,13,0,15,12};
	int as = sizeof(arr)/sizeof(arr[0]);
	for(int j=1;j<as;j++)
	{
		int key = arr[j];
		int i = j-1;
		while(i>=0 && arr[i]>key)
		{
			arr[i+1] = arr[i];
			i--;
		}
		arr[i+1] = key;
	}

	cout <<"Sorted array : \n";
	for(int k=0;k<as;k++)
	{
		cout<< arr[k]<<", ";
	}
}