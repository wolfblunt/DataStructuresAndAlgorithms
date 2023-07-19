// Kth Smallest Element in a BST

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
    void inorder(TreeNode* root, int k, priority_queue<int> &pq)
    {
        if(!root)
        {
            return;
        }
        else
        {
            if(root->left)
            {
                inorder(root->left, k, pq);
            }
            pq.push(root->val);
            if(pq.size()>k)
            {
                pq.pop();
            }
            if(root->right)
            {
                inorder(root->right, k, pq);
            }
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;
        inorder(root, k, pq);
        return pq.top();
    }
};