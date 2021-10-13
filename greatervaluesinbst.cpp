void solve(Node* root,int &ans){
    if(!root) return;
    solve(root->right,ans);
    int temp = root->data;
    root->data +=ans;
    ans+=temp;
    solve(root->left,ans);
}
Node* modify(Node *root)
{
    // Your code here
    int ans=0;
    solve(root,ans);
    return root;
}