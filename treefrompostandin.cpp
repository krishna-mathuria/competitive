Node *Tree(int in[],int post[],int is,int ie,int *pindex,int n)
{
  if(is>ie)return NULL;
  Node *root=new Node(post[*pindex]);
  (*pindex)--;
  if(is==ie)return root;
  int inindex;
  for(int i=0;i<n;i++)
  {
      if(root->data==in[i])
      inindex=i;
  }
  root->right=Tree(in,post,inindex+1,ie,pindex,n);
  root->left=Tree(in,post,is,inindex-1,pindex,n);
  return root;
}
Node *buildTree(int in[], int post[], int n) {
   int pindex=n-1;
   int ie=0;
   int is=n-1;
   return Tree(in,post,ie,is,&pindex,n);
}