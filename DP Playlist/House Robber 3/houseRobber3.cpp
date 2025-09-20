// House Robber III : O(n)

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
    pair<int, int> helper(TreeNode* root)
    {
        if(!root)
        {
            return {0, 0};
        }

        pair<int, int> leftValue = helper(root->left);
        pair<int, int> rightValue = helper(root->right);

        int pick = root->val + leftValue.second + rightValue.second;
        int notPick = max(leftValue.first, leftValue.second) + max(rightValue.first, rightValue.second);

        return {pick, notPick};
    }

    int rob(TreeNode* root) {
        pair<int, int> ans = helper(root);
        return max(ans.first, ans.second);
    }
};