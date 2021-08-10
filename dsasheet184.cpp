class Solution{
  public:
    /*You are required to complete this method*/
    bool isLeaf(Node *root){
        return !root->left && !root->right;
    }
    bool checkh(Node *root,int h,int k){
        if(root==NULL) return 1;
        if(isLeaf(root) && k==h)
            return 1;
        else if(isLeaf(root) && k!=h) return 0;
        bool a = checkh(root->left,h,k+1);
        bool b = checkh(root->right,h,k+1);
        return a&&b;
        
    }
    bool check(Node *root)
    {
        //Your code here
        Node *curr = root;
        int i=1;
        while(!isLeaf(curr)){
            if(curr->left!=NULL) {
                curr = curr->left;
                i++;
            }
            else if(curr->right!=NULL){
                curr = curr->right;
                i++;
            }
        }
        return checkh(root,i,1);
    }
};