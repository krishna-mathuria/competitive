void solve(struct Node *root, int k, vector<int> &arr){
   if((root->left==NULL && root->right==NULL) || k==0 ){
       if(k==0){
           arr.push_back(root->data);
       }
       return;
   }
   if(root->left!=NULL){
       solve(root->left,k-1,arr);
   }
   if(root->right!=NULL){
       solve(root->right,k-1,arr);
   }
   
}
vector<int> Kdistance(struct Node *root, int k)
{
 vector<int> arr;
 solve(root,k,arr);
 return arr;
}