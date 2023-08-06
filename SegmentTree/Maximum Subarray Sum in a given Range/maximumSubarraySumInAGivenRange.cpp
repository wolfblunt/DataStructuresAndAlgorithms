// Maximum Subarray Sum in a given Range

#include<bits/stdc++.h>
using namespace std;

const int n = 1e5+2, mod = 1e9+7;

class Node
{
public:
	int maxPrefixSum;
	int maxSuffixSum;
	int totalSum;
	int maxSubarraySum;

	Node()
	{
		maxPrefixSum = maxSuffixSum = maxSubarraySum = 0;
		totalSum = INT_MIN;
	}
};

Node segTree[4*n];
int a[n];

Node merge(Node leftChild, Node rightChild)
{
	Node parentNode;
	parentNode.maxPrefixSum = max(leftChild.maxPrefixSum, leftChild.totalSum + rightChild.maxPrefixSum);

	parentNode.maxSuffixSum = max(rightChild.maxSuffixSum, leftChild.maxSuffixSum + rightChild.totalSum);

	parentNode.totalSum = leftChild.totalSum + rightChild.totalSum;

	parentNode.maxSubarraySum = max(leftChild.maxSubarraySum, max(rightChild.maxSubarraySum, leftChild.maxSuffixSum + rightChild.maxPrefixSum));

	return parentNode;
}

void buildTree(int index, int start, int end)
{
	if(start == end)
	{
		if(a[start] <= 0)
		{
			segTree[index].totalSum = a[start];
			segTree[index].maxPrefixSum = segTree[index].maxSuffixSum = segTree[index].maxSubarraySum = 0;
		}
		else
		{
			segTree[index].totalSum = segTree[index].maxPrefixSum = segTree[index].maxSuffixSum = segTree[index].maxSubarraySum = a[start];
		}

		return;
	}

	int mid = (start + end)/2;

	buildTree(2*index+1, start, mid);
	buildTree(2*index+2, mid+1, end);

	segTree[index] = merge(segTree[2*index+1], segTree[2*index+2]);
}

void update(int index, int start, int end, int updateIndex, int value)
{
	if(start == end)
	{
		if(updateIndex == start)
		{
			a[start] = value;
			if(a[start] <= 0)
			{
				segTree[index].totalSum = a[start];
				segTree[index].maxPrefixSum = segTree[index].maxSuffixSum = segTree[index].maxSubarraySum = 0;
			}
			else
			{
				segTree[index].totalSum = segTree[index].maxPrefixSum = segTree[index].maxSuffixSum = segTree[index].maxSubarraySum = a[start];
			}

			return;
		}
	}

	int mid = (start + end)/2;
	if(updateIndex <= mid)
		update(2*index+1, start, mid, updateIndex, value);
	else
		update(2*index+2, mid+1, end, updateIndex, value);

	segTree[index] = merge(segTree[2*index+1], segTree[2*index+2]);	
}

int main()
{
	int nn, mm;
	cin>>nn>>mm;

	for(int i=0; i<nn; i++)
	{
        cin >> a[i];
    }
    buildTree(0, 0, nn-1);
    cout<< segTree[0].maxSubarraySum <<endl;
    while(mm--)
    {
    	int index, value;
    	cin>>index>>value;
    	update(0,0,nn-1,index,value);
    	cout<< segTree[0].maxSubarraySum <<endl;
    }

    return 0;
}
