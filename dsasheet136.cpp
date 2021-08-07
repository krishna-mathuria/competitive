Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node *curr1,*curr2;
    curr1=head1;
    curr2=head2;
    Node *ans = new Node(0);
    Node *res=ans;
    while(curr1!=NULL && curr2!=NULL){
        if(curr1->data==curr2->data){
            Node *new_node = new Node(curr1->data);
            ans->next = new_node;
            ans = ans->next;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        else if(curr1->data>curr2->data){
            curr2=curr2->next;
        }
        else{
            curr1=curr1->next;
        }
    }
    return res->next;
}