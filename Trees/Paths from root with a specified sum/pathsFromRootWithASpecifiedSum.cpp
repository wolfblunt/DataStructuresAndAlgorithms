// Paths from root with a specified sum

/*// A Tree node
struct Node
{
	int key;
	struct Node *left, *right;
};*/

class Solution
{
    public:
    void helper(Node *root, int &target, vector<vector<int>> &ans, vector<int> temp, int currSum)
    {
        if(currSum == target)
        {
            ans.push_back(temp);
        }
        
        if(root->left)
        {
            temp.push_back(root->left->key);
            helper(root->left, target, ans, temp, currSum+root->left->key);
            temp.pop_back();
        }
        if(root->right)
        {
            temp.push_back(root->right->key);
            helper(root->right, target, ans, temp, currSum+root->right->key);
            temp.pop_back();
        }
        return;
    }
    
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        if(root==NULL)
        {
            return ans;
        }
        temp.push_back(root->key);
        helper(root, sum, ans, temp, root->key);
        return ans;
    }
};