class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void solve(Node* root,vector<int> &arr){
        if(root==NULL) return;
        solve(root->left,arr);
        arr.push_back(root->data);
        solve(root->right,arr);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> arr1;
       vector<int> arr2;
       solve(root1,arr1);
       solve(root2,arr2);
       vector<int> arr(arr1.size()+arr2.size());
       std::merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), arr.begin());
       return arr;
    }
    
};