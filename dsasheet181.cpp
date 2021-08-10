class Solution{
    public:
    int search(int in[],int k,int n){
        for(int i=0;i<n;i++)
        if(in[i]==k) return i;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        if(n==0){
            return NULL;
        }
        Node *temp = new Node(pre[0]);
        int i =search(in, pre[0],n);
        temp->left = buildTree(in,pre+1,i);
        temp->right = buildTree(in+i+1,pre+i+1,n-i-1);
        return temp;
    }
};