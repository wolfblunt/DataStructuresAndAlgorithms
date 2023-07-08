// Boundary Traversal of binary tree

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    /* 

    Approach: Boundary traversal in an anti-clockwise direction can be described as a traversal consisting of three parts:
    
    Part 1: Left Boundary of the tree (excluding the leaf nodes). -> levelOrder Traversal
    Part 2: All the leaf nodes travelled in the left to right direction.  -> Inorder Traversal
    Part 3: Right Boundary of the tree (excluding the leaf nodes), traversed in the reverse direction.  -> levelOrder Traversal
    
    */
    bool isLeaf(Node* root)
    {
        return !root->left && !root->right;
    }
    
    void addLeftBoundary(Node* root, vector<int>& ans)
    {
        Node* curr = root->left;
        while(curr)
        {
            if(!isLeaf(curr))
            {
                ans.push_back(curr->data);
            }
            if(curr->left)
            {   
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
    }
    
    void addLeaves(Node* root, vector<int>& ans)
    {
        if(isLeaf(root))
        {
            ans.push_back(root->data);
            return;
        }
    
        if(root->left)
        {
            addLeaves(root->left, ans);
        }
    
        if(root->right)
        {
            addLeaves(root->right, ans);
        }
    }
    
    void addRightBoundary(Node* root, vector<int>& ans)
    {
        vector<int> temp;
        Node* curr = root->right;
        while(curr)
        {
            if(!isLeaf(curr))
            {
                temp.push_back(curr->data);
            }
            if(curr->right)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }
    
        for(int i=temp.size()-1;i>=0;i--)
        {
            ans.push_back(temp[i]);
        }
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(!root)
        {
            return ans;
        }
    
        if(!isLeaf(root))
        {
            ans.push_back(root->data);
        }
    
        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);
    
        return ans;
    }
};