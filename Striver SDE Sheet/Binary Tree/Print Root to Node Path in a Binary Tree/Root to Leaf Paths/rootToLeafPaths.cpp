// Root to Leaf Paths

/* Structure of Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/

void dfs(Node* root, vector<int> &curr, vector<vector<int>> &result)
{
    if(!root->left && !root->right)
    {
        curr.push_back(root->data);
        result.push_back(curr);
        curr.pop_back();
        return;
    }
    if(root->left)
    {
        curr.push_back(root->data);
        dfs(root->left, curr, result);
        curr.pop_back();
    }

    if(root->right)
    {
        curr.push_back(root->data);
        dfs(root->right, curr, result);
        curr.pop_back();
    }
}

/* The function should print all the paths from root
 to leaf nodes of the binary tree */
vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>> result;
    vector<int> curr;
    if(root)
        dfs(root, curr, result);

    return result;
}