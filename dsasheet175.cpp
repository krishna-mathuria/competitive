bool func(Node *root,int* height){
    int lh=0,rh=0;
    int l=0,r=0;
    if(root==NULL){
        *height = 0;
        return 1;
    }
    l = func(root->left,&lh);
    r = func(root->right,&rh);
    *height = (lh>rh ? lh:rh)+1;
    if(abs(lh-rh)>=2){
        return 0;
    }
    else return l && r;
}

bool isBalanced(Node *root)
{
    //  Your Code here
    int height =0;
    return func(root,&height);
}