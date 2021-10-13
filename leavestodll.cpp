void buildDLL(Node* root, Node* &ptr){
    Node* temp=new Node(root->data);
    ptr->right=temp;
    temp->left=ptr;
    ptr=ptr->right;
}

void helper(Node* root, Node* prev, Node* &ptr){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        buildDLL(root,ptr);
        if(prev->right==root){
            prev->right=NULL;
        }
        else{
            prev->left=NULL;
        }
        return;
    }
    helper(root->left,root,ptr);
    helper(root->right,root,ptr);
}
Node * convertToDLL(Node *root){
    Node* DLL=new Node(-1);
    Node* ptr=DLL;
    helper(root,NULL,ptr);
    DLL=DLL->right;
    DLL->left=NULL;
    return DLL;
}