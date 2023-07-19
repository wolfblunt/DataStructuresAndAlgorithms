// Maximum Sum BST in Binary Tree

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
class NodeValue
{
public:
    int maxNode, minNode, sum;

    NodeValue(int minNode, int maxNode, int sum)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};


class Solution {
public:
    int maxSum = 0;

    NodeValue largestBSTSubtreeChecker(TreeNode* root) 
    {
        if(!root)
        {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        auto left = largestBSTSubtreeChecker(root->left);
        auto right = largestBSTSubtreeChecker(root->right);

        if(left.maxNode < root->val && right.minNode > root->val)
        {
            // It is a valid BST
            int currSum = left.sum + right.sum + root->val;
            maxSum = max(currSum, maxSum);
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), currSum);
        }

        return NodeValue(INT_MIN, INT_MAX, 0);
    }

    int maxSumBST(TreeNode* root) {
        largestBSTSubtreeChecker(root);
        return maxSum;
    }
};