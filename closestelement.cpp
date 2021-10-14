class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
    int minDiff(Node *root, int K)
    {
        //Your code here
        if(root==NULL) return INT_MAX;
        if(root->data==K) return 0;
        else{
            if(root->data>K) return min(abs(root->data-K),minDiff(root->left,K));
            else return min(abs(root->data-K),minDiff(root->right,K));
        }
    }
};
