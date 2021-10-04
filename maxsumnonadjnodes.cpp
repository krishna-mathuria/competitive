class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    unordered_map<Node*,int> dp;
    
    int getMaxSum(Node *root) 
    {
        // Add your code here
        if(root==NULL) return 0;
        if(dp[root]!=0) return dp[root];
        int inc = root->data;
        if(root->left!=NULL){
            inc+=getMaxSum(root->left->left) + getMaxSum(root->left->right);
        }
        if(root->right!=NULL){
            inc += getMaxSum(root->right->left) + getMaxSum(root->right->right);
        }
        int temp = 0;
        temp +=getMaxSum(root->left)+getMaxSum(root->right);
        dp[root] = max(temp,inc);
        return dp[root];
    }
};