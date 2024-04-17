// Smallest String Starting From Leaf

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
    void helper(TreeNode* root, string &smallestString, string temp)
    {
        if(!root)
        {
            return;
        }

        temp += char('a' + root->val);
        if(!root->left && !root->right)
        {
            reverse(temp.begin(), temp.end());

            if(smallestString.empty() || smallestString > temp)
            {
                smallestString = temp;
            }

            reverse(temp.begin(), temp.end());
        }

        helper(root->left, smallestString, temp);
        helper(root->right, smallestString, temp);
    }

    string smallestFromLeaf(TreeNode* root) {
        string smallestString = "";
        helper(root, smallestString, "");
        return smallestString;
    }
};