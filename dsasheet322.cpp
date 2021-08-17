class Solution {
  public:
bool isHeap(struct Node * tree)
{
    
    queue<Node*> q; q.push(tree);
    int t=0;
    while(q.size()!=0)
    {
        Node *temp=q.front(); q.pop();
        if(temp!=NULL)
        {
            if(t)
            {
                return false;
            }
            Node * largest=temp;
            if(temp->left && largest->data<temp->left->data)
                largest=temp->left;
            if(temp->right && largest->data < temp->right->data)
                largest=temp->right;
            if(largest!=temp) return false;
            q.push(temp->left);
            q.push(temp->right);
        }
        else
        {
            t=1;
        }
    }
    return true;

}
};