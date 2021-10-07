class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return {};
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            Node* prev = NULL;
            while(size--){
                Node* temp = q.front();
                q.pop();
                temp->next=prev;
                prev= temp;
                if(temp->right) q.push(temp->right);
                if(temp->left) q.push(temp->left);
            }
        }
        return root;
    }
};