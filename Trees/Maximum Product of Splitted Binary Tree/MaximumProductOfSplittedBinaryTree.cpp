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
    int mod = 1e9+7;
    long long treeTotal=0;
    long long result=0;
    void treeTotalSum(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        treeTotal+=root->val;
        treeTotalSum(root->left);
        treeTotalSum(root->right);
    }

    int treeSumUnder(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        int sumUnderLeft = treeSumUnder(root->left);
        int sumUnderRight = treeSumUnder(root->right);
        result = max(result, max((treeTotal - sumUnderLeft) * sumUnderLeft, (treeTotal - sumUnderRight) * sumUnderRight));
        return sumUnderLeft + sumUnderRight + root->val;
    }

    int maxProduct(TreeNode* root) {
        treeTotalSum(root);
        treeSumUnder(root);
        return result%mod;
    }
};