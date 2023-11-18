// Binary Tree to CDLL

/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
  public:
    void inorder(Node* root, Node* &head, Node* &temp)
    {
        if(!root)
        {
            return; 
        }
        inorder(root->left, head, temp);
        if(head == NULL)
        {
            head = root;
            temp = root;
        }
        else
        {
            root->left = temp;
            temp->right = root;
            temp = root;
        }
        inorder(root->right, head, temp);
    }
  
    //Function to convert binary tree into circular doubly linked list.
    Node *bTreeToCList(Node *root)
    {
        Node* temp = NULL;
        Node* head = NULL;
        inorder(root, head, temp);
        // circular array condition
        temp->right = head;
        head->left = temp;
    }
};