bool isCircular(Node *head)
{
   // Your code here
      Node *curr;
    curr=head;
    while(curr!=NULL){
        if(curr->data==-1) return true;
        curr->data =-1;
        curr = curr->next;
    }
    return false;
}