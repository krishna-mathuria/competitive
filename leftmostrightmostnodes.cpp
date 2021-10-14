void printCorner(Node *root)
{
    if(!root) return;
// Your code goes here
    queue<Node*> q;
    q.push(root);
    
    cout<<root->data<<" ";
    q.pop();
    if(root->left)
    q.push(root->left);
    if(root->right)
    q.push(root->right);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        int size = q.size();
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        while(size--){
            Node* temp2 = q.front();
            q.pop();
            if(temp2->left) q.push(temp2->left);
            if(temp2->right) q.push(temp2->right);
            if(size==0) cout<<temp2->data<<" ";
        }
    }
}