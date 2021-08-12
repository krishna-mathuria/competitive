int minValue(Node* root)
{
    // Code here
    if(root==NULL) return 0;
    Node *curr=root;
    while(curr->left!=NULL){
        curr = curr->left;
    }
    return curr->data;
}
