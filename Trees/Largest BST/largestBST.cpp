// Largest BST

/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    struct child
    {
        int size;
        int min;
        int max;
        int isBst;
        int ans;
    };
    
    child dfs(Node* root)
    {
        if(root == NULL)
        {
            return {0,INT_MAX,INT_MIN,1,0};
        }
        child l = dfs(root->left);
        child r = dfs(root->right);
        
        if(l.isBst && l.max < root->data && r.isBst && r.min > root->data)
        {
            child node;
            node.size = l.size + r.size + 1;
            node.isBst = 1;
            node.min = min({l.min,r.min,root->data});
            node.max = max({l.max,r.max,root->data});
            node.ans = node.size;
            return node;
        }
        
        child node;
        node.size = l.size + r.size + 1;  
        node.isBst = 0;
        node.min = min({l.min, r.min, root->data});  
        node.max = max({l.max, r.max, root->data});
        node.ans = max(l.ans, r.ans);  
        return node;

    }
    
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	return dfs(root).ans;
    }
};