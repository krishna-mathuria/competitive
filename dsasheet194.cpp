void generateArray(Node *root, int ancestors[])
{
    ancestors[root->data] = -1;
 
    queue<Node*> q;
    q.push(root);
 
    while(!q.empty())
    {
        Node* temp  = q.front();
        q.pop();
 
        if (temp->left)
        {
            ancestors[temp->left->data] = temp->data;
            q.push(temp->left);
        }
 
        if (temp->right)
        {
            ancestors[temp->right->data] = temp->data;
            q.push(temp->right);
        }
    }
}
 
// function to calculate Kth ancestor
int kthAncestor(Node *root, int n, int k, int node)
{

    int ancestors[n+1] = {0};
 
    generateArray(root,ancestors); 

    int count = 0;
 
    while (node!=-1)
    {  
        node = ancestors[node];
        count++;
 
        if(count==k)
            break;
    }
 
    // print Kth ancestor
    return node;
}