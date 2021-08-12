void traverse(Node *root,bool &b,int l,int r){
    if(!b || !root)
        return;
    if(l==r || r==1)
        b=0;
    traverse(root->left,b,l,root->data-1);
    traverse(root->right,b,root->data+1,r);
}
bool isDeadEnd(Node *root)
{
    //Your code here
    bool b =1;
    traverse(root,b,0,INT_MAX);
    return !b;
}