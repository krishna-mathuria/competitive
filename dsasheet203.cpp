Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
    if(root==NULL) return NULL;
    Node *left=NULL,*right=NULL;
    if(n1>n2) swap(n1,n2);
    if(root->data==n1 || root->data==n2){
       return root;
    }
    if(root->data>n1 && root->data<n2) return root;
    else if(root->data>n1)
        left = LCA(root->left,n1,n2);
    else{
        right = LCA(root->right,n1,n2);        
    }
    return left ? left : right;
}
