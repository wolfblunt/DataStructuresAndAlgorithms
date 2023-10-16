// Duplicate subtree in Binary Tree

/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  public:
    unordered_map<string, int> um;
    
    string helper(Node* root)
    {
        if(!root)
        {
            return "$";
        }
        if(!root->left && !root->right)
        {
            string s = to_string(root->data);
            return s;
        }
        
        string s = to_string(root->data);
        s += helper(root->left);
        s += helper(root->right);
        um[s]++;
        return s;
    }
    
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root) {
        um.clear();
        helper(root);
        for(auto a: um)
        {
            if(a.second > 1)
            {
                return true;
            }
        }
        
        return false;
    }
};