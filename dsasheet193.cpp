    Node* lca(Node* root ,int n1 ,int n2 )
    {
        Node *lnode, *rnode;
        if(!root){
            return NULL;
        }
        
        if(root->data == n1 || root->data == n2){
            return root;
        }
        
        lnode = lca(root->left, n1, n2);
        rnode = lca(root->right, n1, n2);
        
        if(lnode && rnode){
            return root;
        }
        
        return (lnode != NULL) ? lnode : rnode;
    }
   
    int search(Node * root,int key,int level){
        if(root==NULL)
            return -1;
        if(root->data==key)
            return level;
            
        int left=search(root->left,key,level+1);
        if(left!=-1)
            return left;
            
        return search(root->right,key,level+1);
    }
    int findDist(Node* root, int a, int b) {
    // Your code here
        Node* lca_node=lca(root,a,b);
        int l1=search(lca_node,a,0);
        int l2=search(lca_node,b,0);
        return l1+l2;
    }