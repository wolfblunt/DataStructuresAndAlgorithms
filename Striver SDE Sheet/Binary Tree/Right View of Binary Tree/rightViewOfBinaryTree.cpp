// Right View of Binary Tree

/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution
{
    public:
    void helper(Node* root, vector<int> &ans, int level)
    {
        if(!root)
        {
            return;
        }
        
        if(ans.size() ==  level)
        {
            ans.push_back(root->data);
        }
        
        helper(root->right, ans, level+1);
        helper(root->left, ans, level+1);
    }
    
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       if(root==NULL)
       {
           return {};
       }
       helper(root, ans, 0);
       return ans;
    }
};