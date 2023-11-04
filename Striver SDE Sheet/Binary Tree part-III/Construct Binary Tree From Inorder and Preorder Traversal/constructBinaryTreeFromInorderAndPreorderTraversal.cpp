// Construct Binary Tree From Inorder and Preorder Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> um;
    TreeNode* makeTree(vector<int>& preorder, vector<int>& inorder, int start, int end, int &index)
    {
        if(start > end)
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[index]);
        int pivot = um[root->val];
        index++;
        root->left = makeTree(preorder, inorder, start, pivot-1, index);
        root->right = makeTree(preorder, inorder, pivot+1, end, index);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++)
        {
            um[inorder[i]] = i;
        }
        int index = 0;
        return makeTree(preorder, inorder, 0, n-1, index);
    }
};