vector<int> diagonal(Node *root)
{
   // your code here
    queue<Node*> q;
    vector<int> v;
    q.push(root);
    while(!q.empty()){
       Node *curr = q.front();
       v.push_back(curr->data);
       q.pop();
       while(curr!=NULL){
           if(curr->left!=NULL){
               q.push(curr->left);
           }
           if(curr->right!=NULL){
               v.push_back(curr->right->data);
           }
           curr = curr->right;
       }
    }
    return v;
}