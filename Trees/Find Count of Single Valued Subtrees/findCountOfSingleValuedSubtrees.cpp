// Find Count of Single Valued Subtrees

/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
bool countTrees(BinaryTreeNode<int> *root, int &count)
{
    if(!root)
    {
        return true;
    }
    bool left = countTrees(root->left, count);
    bool right = countTrees(root->right, count);

    if(left == false || right == false)
    {
        return false;
    }
    if(root->left && root->left->data != root->data)
    {
        return false;
    }
    if(root->right && root->right->data != root->data)
    {
        return false;
    }

    count++;
    return true;
}

int countUnivalTrees(BinaryTreeNode<int> *root)
{
    int count = 0;
    countTrees(root, count);
    return count;
}