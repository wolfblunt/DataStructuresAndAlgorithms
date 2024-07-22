// Delete Nodes And Return Forest

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
    vector<TreeNode*> remainingRoots;
    set<int> deletedRoots;

    void helper(TreeNode* &root)
    {
        if(root)
        {
            helper(root->left);
            helper(root->right);
            if(deletedRoots.find(root->val) != deletedRoots.end())
            {
                if(root->left)
                {
                    remainingRoots.push_back(root->left);
                }
                if(root->right)
                {
                    remainingRoots.push_back(root->right);
                }

                root = NULL;
                delete root;
            }
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i=0;i<to_delete.size();i++)
        {
            deletedRoots.insert(to_delete[i]);
        }

        helper(root);
        if(root)
        {
            remainingRoots.push_back(root);
        }

        return remainingRoots;
    }
};