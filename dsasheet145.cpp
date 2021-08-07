Node* reverseDLL(Node * head)
{
    //Your code here
    Node *curr,*temp,*ans;
    curr=head;
    while(curr!=NULL){
        ans = curr;
        temp = curr->next;
        swap(curr->next,curr->prev);
        curr = temp;
    }
    return ans;

}