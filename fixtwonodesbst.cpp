class Solution {
  public:
void findnode(Node *root, Node *&prev, Node *&first, Node *&second)
{
    if(root == NULL)
    {
        return;
    }
    
    findnode(root->left, prev, first, second);
    
    if(prev != NULL && root->data < prev->data)
    {
        if(first == NULL)
        {
            first = prev;
        }
        second = root;
    }
    prev = root;
    
    findnode(root->right, prev, first, second);

}

Node *correctBST(Node *root)
{
    Node *prev = NULL, *first = NULL, *second = NULL;
    
    findnode(root, prev, first, second);
    
    swap(first->data, second->data);
    
    return root;
}
};