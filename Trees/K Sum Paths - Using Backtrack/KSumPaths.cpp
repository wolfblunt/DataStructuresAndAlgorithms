// K Sum Paths

/*
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
  public:
    const int mod = 1e9+7;
    int helper(Node* root, int k, map<int, int> &mp, int sum)
    {
        if(root == NULL)
        {
            return 0;
        }
        int ans = 0;
        if(mp.find(sum+root->data - k) != mp.end())
        {
            ans += mp[sum + root->data-k] % mod;
        }
        
        mp[sum+root->data]++;
        ans += (helper(root->left, k, mp, sum+root->data) % mod + 
        helper(root->right, k, mp, sum+root->data) % mod) % mod;
        
        mp[sum+root->data]--;
        return ans%mod;
    }
  
    int sumK(Node *root,int k)
    {
        map<int, int> mp;
        mp[0] = 1;
        return helper(root, k, mp, 0);
    }
};