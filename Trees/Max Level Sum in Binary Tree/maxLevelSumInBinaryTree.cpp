// Max Level Sum in Binary Tree

class Solution{
  public:
    /*You are required to complete below method */
    int maxLevelSum(Node* root) {
        if(root == NULL)
        {
            return 0;
        }
        
        queue<Node*> q;
        
        int maxSum = INT_MIN;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            int levelSum = 0;
            for(int i=0;i<size;i++)
            {
                Node* temp = q.front();
                q.pop();
                levelSum+=temp->data;
                
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
            }
            
            
            maxSum = max(maxSum, levelSum);
        }
        
        return maxSum;
    }
};