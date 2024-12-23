// Minimum Number of Operations to Sort a Binary Tree by Level - O(nlogn)

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

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
    int findMinSwaps(vector<int> &v)
    {
        int minSwaps = 0;
        map<int, int> sorted_map;
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            sorted_map[v[i]] = i;
        }
        sort(v.begin(), v.end());
        int iterator = 0;
        vector<bool> visited(n, false);
        for(auto& [val, idx]: sorted_map)
        {
            if(visited[idx])
            {
                iterator++;
                continue;
            }

            visited[idx] = 1;
            int len = 1; // current length
            while(idx != iterator)
            {
                idx = sorted_map[v[idx]];
                visited[idx] = true;
                len++;
            }
            minSwaps += len-1;
            iterator++;
        }

        return minSwaps;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int totalSwaps = 0;
        while(!q.empty())
        {
            int n = q.size();
            vector<int> v;
            while(n--)
            {
                auto curr = q.front(); 
                q.pop();
                v.push_back(curr->val);
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
            totalSwaps += findMinSwaps(v);
        }

        return totalSwaps;
    }
};