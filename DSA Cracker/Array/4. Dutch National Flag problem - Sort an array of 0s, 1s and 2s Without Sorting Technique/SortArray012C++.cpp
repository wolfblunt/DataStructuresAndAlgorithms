// Sort an array of 0s, 1s and 2s | Dutch National Flag problem

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> arr = {0,2,1,2,0};
	int low=0,mid=0;
	int high = arr.size()-1;
	int temp;
	while(mid<=high)
	{
		switch(arr[mid])
		{
			case 0:
				temp = arr[mid];
				arr[mid] = arr[low];
				arr[low] = temp;
				mid++;
				low++;
				break;
			case 1:
				mid++;
				break;
			case 2:
				temp = arr[mid];
				arr[mid] = arr[high];
				arr[high] = temp;
				high--;
		}
	}
	for (auto& it : arr) {
        cout << it << ' ';
    }
	return 0;
}
