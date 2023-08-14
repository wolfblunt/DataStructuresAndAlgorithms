// Level order traversal in spiral form

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


//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    if(!root)
    {
        return {};
    }
    queue<Node*> q;
    vector<int> ans;
    q.push(root);
    int level = 1;
    while(!q.empty())
    {
        int sz = q.size();
        vector<int> curr(sz);
        for(int i=0;i<sz;i++)
        {
            Node* temp = q.front();
            q.pop();
            if(level==0)
            {
                curr[i] = temp->data;
            }
            else
            {
                curr[sz-i-1] = temp->data;
            }
            
            if(temp->left)
                q.push(temp->left);
                
            if(temp->right)
                q.push(temp->right);
        }
        for(auto a: curr)
        {
            ans.push_back(a);
        }
        
        level = !level;
    }
    return ans;
}