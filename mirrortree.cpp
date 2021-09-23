void mirror(struct Node* node) {
    // code here
    if(node==NULL) return;
    struct Node* temp=NULL;
    temp = node->left;
    node->left = node->right;
    node->right = temp;
    mirror(node->left);
    mirror(node->right);
}