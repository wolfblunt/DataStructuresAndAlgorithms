// All Possible Full Binary Trees

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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0)
        {
            return {};
        }

        vector<TreeNode*> result;
        if(n==1)
        {
            result.push_back(new TreeNode(0));
            return result;
        }
        
        for(int i=1;i<=n-1;i+=2)
        {
            vector<TreeNode*> leftTrees = allPossibleFBT(i);
            vector<TreeNode*> rightTrees = allPossibleFBT(n-i-1);

            for(auto l: leftTrees)
            {
                for(auto r: rightTrees)
                {
                    result.push_back(new TreeNode(0, l, r));
                }
            }
        }

        return result;
    }
};