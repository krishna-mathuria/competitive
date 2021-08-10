vector <int> zigZagTraversal(Node* root)
{
	// Code here
    vector<int> v;
    if(root==NULL) return v;
    deque<Node*> q;
    Node *temp;
    bool x=true;
    q.push_back(root);
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            if(x==true){
                temp = q.back();
                q.pop_back();
                v.push_back(temp->data);
                if(temp->left) q.push_front(temp->left);
                if(temp->right) q.push_front(temp->right);
            }
            else {
                temp = q.front();
                q.pop_front();
                v.push_back(temp->data);
                if(temp->right) q.push_back(temp->right);
                if(temp->left) q.push_back(temp->left);
            }
        }
        x=!x;
    }
    return v;
}