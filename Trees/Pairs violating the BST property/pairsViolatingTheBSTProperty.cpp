// Pairs violating the BST property

/*struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:

    void inorderTraversal(Node *root, vector<int>&arr)
    {
        if(!root)
        {
            return;
        }
        inorderTraversal(root->left, arr);
        arr.push_back(root->data);
        inorderTraversal(root->right, arr);
    }
    
    void merge(vector<int>&vec, int low, int mid, int high, int &count)
    {
        vector<int>ans(high - low + 1);
        int i = low, j = mid + 1, k = 0;
        while(i <= mid && j <= high)
        {
            if(vec[i] <= vec[j])
            {
                ans[k++] = vec[i++];
            }
            else
            {
                ans[k++] = vec[j++];
                count += (mid - i + 1);
            }
        }
        while(i <= mid)
        {
            ans[k++] = vec[i++];
        }
        while(j <= high)
        {
            ans[k++] = vec[j++];
        }
        for(i = low; i <= high; i++)
        {
            vec[i] = ans[i - low];
        }
    }
    
    void mergeSort(vector<int>&vec, int low, int high, int &count)
    {
        if(low < high)
        {
            int mid = (low+high)/2;
            mergeSort(vec, low, mid, count);
            mergeSort(vec, mid+1, high, count);
            merge(vec, low, mid, high, count);
        }
    }
    
    int pairsViolatingBST(int n, Node *root) {
        vector<int>vec;
        inorderTraversal(root, vec);
        int count = 0;
        mergeSort(vec, 0, n-1, count);
        return count;
    }
};