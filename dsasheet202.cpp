class Solution
{
public:
    Node *pre=NULL;
    void populateNext(struct Node* root)
    {
        if(root==NULL) return;
        populateNext(root->left);
        if(pre) 
            pre->next=root;
        pre=root;
        populateNext(root->right);
    }
};