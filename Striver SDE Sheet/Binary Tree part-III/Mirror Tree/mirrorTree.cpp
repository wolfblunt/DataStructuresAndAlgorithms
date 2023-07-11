// Mirror Tree - DFS

/* A binary tree node has data, pointer to left child
   and a pointer to right child /
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

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(!node)
            return;
            
        mirror(node->left);
        mirror(node->right);
        
        Node* temp = node->right;
        node->right = node->left;
        node->left = temp;
    }
};