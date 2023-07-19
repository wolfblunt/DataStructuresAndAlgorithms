// Kth largest element in BST - Using Priority Queue

/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    priority_queue<int, vector<int>, greater<int>> pq;
    void inorder(Node* root, int k)
    {
        if(!root)
        {
            return;
        }
        else
        {
            if(root->left)
            {
                inorder(root->left, k);
            }
            pq.push(root->data);
            if(pq.size()>k)
            {
                pq.pop();
            }
            if(root->right)
            {
                inorder(root->right, k);
            }
        }
    }
    
    int kthLargest(Node *root, int k)
    {
        inorder(root, k);
        if(pq.size() < k)
        {
            return -1;
        }
        return pq.top();
    }
};