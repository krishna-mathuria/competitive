class Solution {
public:
int helper(Node* root,int &maxi)
    {
        if(root==NULL)
        return 0;
        if(root->left==NULL && root->right==NULL)
        return root->data;
         
         int leftsum=helper(root->left,maxi);
         int rightsum=helper(root->right,maxi);
         
          if(root->left && root->right)
          {
              maxi=max(maxi,root->data+leftsum+rightsum);
              return max(leftsum,rightsum)+root->data;
          }
          if(root->left==NULL)
          {
              return rightsum+root->data;
          }
          if(root->right==NULL)
          return root->data+leftsum;
    }

    int maxPathSum(Node* root)
    {
         int maxi=INT_MIN;
         int ans=helper(root,maxi);
         if(maxi==INT_MIN)
         return ans;
         return maxi;
    }
};