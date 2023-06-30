// Maximum Width of Binary Tree

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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;

        queue<pair<TreeNode*, long long int>> q;
        q.push({root, 0});
        int ans = 0;

        while(!q.empty())
        {
            long long int curMin = q.front().second;
            int leftMost, rightMost;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                long long int currId = q.front().second - curMin;
                TreeNode* curr = q.front().first;
                q.pop();
                if(i==0)
                {
                    leftMost = currId;
                }
                if(i==size-1)
                {
                    rightMost = currId;
                }
                if(curr->left)
                {
                    q.push({curr->left, 2*currId+1});
                }
                if(curr->right)
                {
                    q.push({curr->right, 2*currId+2});
                }
            }
            ans = max(ans, rightMost-leftMost+1);
        }

        return ans;
    }
};