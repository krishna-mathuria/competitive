void convert(Node *head, TreeNode *&root) {
    // Your code here
    queue<TreeNode*> q;
    root=new TreeNode(head->data);
    
    q.push(root);
    head=head->next;
    
    while(!q.empty()){
    
        TreeNode* parent=q.front();
        q.pop();
        
        if(head!=NULL){
            parent->left=new TreeNode(head->data);
            q.push(parent->left);
            head=head->next;
        }
        
        if(head!=NULL){
            parent->right=new TreeNode(head->data);
            q.push(parent->right);
            head=head->next;
        }
    }
}