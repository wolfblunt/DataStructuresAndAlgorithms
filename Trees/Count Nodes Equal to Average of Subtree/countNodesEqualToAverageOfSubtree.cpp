// Count Nodes Equal to Average of Subtree

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
    pair<int,int> helper(TreeNode* root,int& ans)
    {
        if(!root)
        {
            return {0,0};
        }
        auto leftans = helper(root->left, ans);
        int leftsum = leftans.first;
        int leftCount = leftans.second;

        auto rightans = helper(root->right, ans);
        int rightsum = rightans.first;
        int rightCount = rightans.second;

        int totalCount = leftCount + rightCount + 1;
        int totalSum = leftsum + rightsum + root->val;
        if(totalSum/totalCount == root->val)
        {
            ans++;
        }

        return {totalSum, totalCount};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};