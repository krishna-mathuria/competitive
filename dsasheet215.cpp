int FindNextGreater(int pre[],int l,int r)
{
    int i;
    for(i=l;i<=r;i++)
        if(pre[i]>pre[l]) return i;
    return i;
}

Node* PreToPost(int pre[],int l,int r)
{
    if(l>r) return NULL;
    int g=FindNextGreater(pre,l,r);
    Node* root=new Node();
    root->left=PreToPost(pre,l+1,g-1);
    root->right=PreToPost(pre,g,r);
    root->data=pre[l];
}

Node* constructTree(int pre[], int size) {
//code here
    int l=0;
    int r=size-1;
    return PreToPost(pre,l,r);
}