// Amount of Time for Binary Tree to Be Infected

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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> adj;  //adjacency list
        queue<pair<TreeNode*, int>> q;
        q.push({root, -1});
        while(q.size())
        {
            TreeNode* node = q.front().first;
            int parent = q.front().second;
            q.pop();
            if(parent != -1)
            {
                adj[parent].push_back(node->val);
                adj[node->val].push_back(parent);
            }
            if(node->left)
            {
                q.push({node->left, node->val});
            }
            if(node->right)
            {
                q.push({node->right, node->val});
            }
        }

        queue<int> bq;
        bq.push(start);
        unordered_map<int,bool> visited;
        visited[start] = true;
        int time = 0;
        while(!bq.empty())
        {
            int n = bq.size();
            for(int i=0;i<n;i++)
            {
                int node = bq.front();
                bq.pop();
                for(auto a: adj[node])
                {
                    if(!visited[a])
                    {
                        bq.push(a);
                        visited[a] = true;
                    }
                }
            }
            time+=1;
        }

        return time-1;
    }
};