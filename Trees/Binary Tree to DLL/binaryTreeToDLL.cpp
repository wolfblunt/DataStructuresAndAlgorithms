// Binary Tree to DLL

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
class Solution {
  public:
    Node* head = NULL;
    Node* tail = NULL;
    
    void helper(Node* root)
    {
        if(!root)
        {
            return;
        }
        
        helper(root->left);
        
        if(head == NULL)
        {
            head = tail = root;
        }
        else
        {
            tail->right = root;
            root->left = tail;
        }
        tail = root;
        
        helper(root->right);
    }
    
    Node* bToDLL(Node* root) 
    {
        helper(root);
        return head;
    }
};