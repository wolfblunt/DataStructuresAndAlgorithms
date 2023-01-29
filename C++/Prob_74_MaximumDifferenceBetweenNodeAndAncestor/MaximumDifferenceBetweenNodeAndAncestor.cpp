// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/

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
    void findMaxDifference(TreeNode* root, int maxValue, int minValue, int& value)
    {
        if(root==NULL)
        {
            return;
        }
        if(maxValue!=INT_MIN)
        {
            value = max(value, abs(maxValue - root->val));
        }
        if(minValue!=INT_MAX)
        {
            value = max(value, abs(minValue - root->val));
        }
        minValue = min(minValue, root->val);
        maxValue = max(maxValue, root->val);
        findMaxDifference(root->left, maxValue, minValue, value);
        findMaxDifference(root->right, maxValue, minValue, value);
    }

    int maxAncestorDiff(TreeNode* root) {
        int maxValue = INT_MIN;
        int minValue = INT_MAX;
        int value=0;
        findMaxDifference(root, maxValue, minValue, value);
        return value;
    }
};