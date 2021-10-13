struct Node* solve(int n,int pre[],char preLN[],int &i){
    if(i==n) return NULL;
    Node *root=new Node(pre[i++]);
    if(preLN[i-1]=='L'){
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    else{
        root->left = solve(n,pre,preLN,i);
        root->right = solve(n,pre,preLN,i);
        return root;
    }
}

struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    int i=0;
    Node* root = solve(n,pre,preLN,i);
    return root;
}