// All Nodes Distance K in Binary Tree

/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
    Node* targetNode = NULL;
public:
    void getRef(Node* root, int target)
    {
        if(root==NULL)
        {
            return;
        }
            
        if(root->data == target)
        {
            targetNode = root;
            return;
        }
        
        getRef(root->left,target);
        getRef(root->right, target);
    }
    
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        vector<int> ans;
        unordered_map<int, Node*> parent;  // value -> parentNode
        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                Node* curr = q.front();
                q.pop();

                if(curr->left)
                {
                    parent[curr->left->data] = curr;
                    q.push(curr->left);
                }

                if(curr->right)
                {
                    parent[curr->right->data] = curr;
                    q.push(curr->right);
                }
            }
        }

        unordered_map<int, int> visited;  // nodeValue -> 1/0  => 1: Visited and 0: NotVisited
        getRef(root,target);;
        q.push(targetNode);
        while(k-- && !q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                Node* curr = q.front();
                q.pop();

                visited[curr->data] = 1;

                if(curr->left && !visited[curr->left->data])
                {
                    q.push(curr->left);
                }

                if(curr->right && !visited[curr->right->data])
                {
                    q.push(curr->right);
                }

                if(parent[curr->data] && !visited[parent[curr->data]->data])
                {
                    q.push(parent[curr->data]);
                }
            }
        }

        while(!q.empty())
        {
            ans.push_back(q.front()->data);
            q.pop();
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};