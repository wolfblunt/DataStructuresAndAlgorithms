// Height of the Binary Tree From Inorder and Level Order Traversal

#include <bits/stdc++.h> 

class Temp {
public:
    int height;
    int leftIndex;
    int rightIndex;

    Temp(int h, int li, int ri) {
        height = h;
        leftIndex = li;
        rightIndex = ri;
    }
};

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
	int maxHeight = 0;
	queue<Temp> q;

	Temp temp(0,0,N-1);  // ('HEIGHT', 'LEFTINDEX', 'RIGHTINDEX')
	q.push(temp);

	unordered_map<int,int> um; // {inorderElement, indexInInorderArray}
	for(int i=0;i<N;i++)
	{
		um[inorder[i]] = i;
	}

	for(int i=0;i<N;i++)
	{
		Temp curr = q.front();
		q.pop();

		maxHeight = max(maxHeight, curr.height);

		int li = curr.leftIndex;
		int ri = curr.rightIndex;
		int rootIndex = um[levelOrder[i]];

		if(rootIndex - 1 >= li)
		{
			Temp leftSubTree(curr.height + 1, li, rootIndex-1);
			q.push(leftSubTree);
		}

		if(rootIndex + 1 <= ri)
		{
			Temp rightSubTree(curr.height + 1, rootIndex+1, ri);
			q.push(rightSubTree);
		}
	}

	return maxHeight;

}