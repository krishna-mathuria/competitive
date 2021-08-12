void preorder(Node* root, int l, int h,int &count){
    if(root==NULL) return;
    if(root->data >=l && root->data <=h) {
        count++;
        preorder(root->left,l,h,count);
        preorder(root->right,l,h,count);
    }
    else if(root->data<l){
        preorder(root->right,l,h,count);
    }
    else if(root->data>h){
        preorder(root->left,l,h,count);
    }
    
}
int getCount(Node *root, int l, int h)
{
  // your code goes here 
  int count = 0;
  preorder(root,l,h,count);
  return count;
}
