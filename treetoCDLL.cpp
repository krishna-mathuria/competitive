
class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    Node* head = NULL;
    Node* tail = NULL;
    void solve(Node* root){
        if(root->left)
            solve(root->left);
        if(!head){
            head= root;
            tail = root;
        }else{
            tail->right = root;
            root->left = tail;
            tail = root;
        }
        if(root->right){
            solve(root->right);
        }
    }
    Node *bTreeToCList(Node *root)
    {
    //add code here.

    solve(root);
    head->left = tail;
    tail->right = head;
    return head;
    }
};