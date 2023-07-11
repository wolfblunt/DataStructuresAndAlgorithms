// Children Sum Parent

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        if(!root)
        {
            return true;
        }
        
        if(root->left && root->right)
        {
            if(root->data != root->left->data + root->right->data)
            {
                return false;
            }
        }
        
        else if(root->left && root->left->data != root->data)
        {
            return false;
        }
        
        else if(root->right && root->right->data != root->data)
        {
            return false;
        }
        
        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};