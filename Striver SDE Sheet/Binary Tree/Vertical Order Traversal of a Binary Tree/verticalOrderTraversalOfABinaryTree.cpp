// Vertical Order Traversal of a Binary Tree

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;  // using multiset because tree elements value can be same
        // mp - {verticalDis: {horixontalDis : [multiset]}}
        queue<pair<pair<int,int>, TreeNode*>> q;  // {{vd, hd}, treeNode}
        // vd - vertical distance  &&  hd - horizontal distance
        q.push({{0,0}, root});
        while(!q.empty())
        {
            TreeNode* curr = q.front().second;
            int v = q.front().first.first;  // vertical distance
            int l = q.front().first.second;  // horizontal distance
            q.pop();
            if(curr == NULL)
            {
                continue;
            }
            mp[v][l].insert(curr->val);
            q.push({{v-1, l+1}, curr->left});
            q.push({{v+1, l+1}, curr->right});
        }

        vector<vector<int>> res;

        for(auto a: mp)
        {
            vector<int> temp;
            for(auto b: a.second)
            {
                for(auto c: b.second)
                {
                    temp.push_back(c);  // inserting all the same vertical distance value in the same vector
                }
            }
            res.push_back(temp);
        }

        return res;
    }
};