// Normal BST to Balanced BST

/*Structure of the Node of the BST is as
struct Node
{
	int data;
	Node* left, *right;
};
*/

class Solution{
    
    public:
    void inOrder(Node* root, vector<Node*> &v)
    {
        if(!root)
        {
            return;
        }
        inOrder(root->left, v);
        v.push_back(root);
        inOrder(root->right, v);
    }
    
    Node* reConstructTree(vector<Node*> &v, int start, int end)
    {
        if(start>end)
        {
            return NULL;
        }
        int mid = start + (end-start)/2;
        Node* root = v[mid];
        root->left = reConstructTree(v, start, mid-1);
        root->right = reConstructTree(v, mid+1, end);
        return root;
    }
    
    // Your are required to complete this function
    // function should return root of the modified BST
    Node* buildBalancedTree(Node* root)
    {
    	vector<Node*> v;
    	inOrder(root, v);
    	int start = 0;
    	int end = v.size()-1;
    	return reConstructTree(v, start, end);
    }
};