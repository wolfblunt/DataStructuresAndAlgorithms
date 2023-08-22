// Maximum Width In Binary Tree

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    if(!root)
        return 0;

    queue<pair<TreeNode<int>*, int>> q; // <Node, index>
    q.push({root, 0});
    int ans = 0;

    while(!q.empty())
    {
        int curMin = q.front().second;
        int leftMost, rightMost;
        int size = q.size();
        ans = max(ans, size);
        for(int i=0;i<size;i++)
        {
            int currId = q.front().second - curMin;
            TreeNode<int>* curr = q.front().first;
            q.pop();
            if(i==0)
            {
                leftMost = currId;
            }
            if(i==size-1)
            {
                rightMost = currId;
            }
            if(curr->left)
            {
                q.push({curr->left, 2*currId+1});
            }
            if(curr->right)
            {
                q.push({curr->right, 2*currId+2});
            }
        }
        ans = max(ans, rightMost-leftMost+1);
    }

    return ans;
}