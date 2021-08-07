int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node *curr,*curr2;
    int c1=0,c2=0;
    int ahead;
    curr=head1;
    while(curr!=NULL){
        c1++;
        curr=curr->next;
    }
    curr=head2;
    while(curr!=NULL){
        c2++;
        curr = curr->next;
    }
    curr = head1;
    curr2 = head2;
    if(c1>=c2){
        ahead = c1-c2;
        for(int i=0;i<ahead;i++){
            curr=curr->next;
        }
    }else{
        ahead = c2-c1;
        for(int i=0;i<ahead;i++){
            curr2=curr2->next;
        }
    }
    while(curr->next!=curr2->next){
        curr=curr->next;
        curr2 = curr2->next;
    }
    if(curr->next ==NULL) return -1;
    else return curr->next->data;

}
