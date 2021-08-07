void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    Node *slow,*fast;
    slow=head;
    fast=head;
    while(fast->next!=head && fast->next->next!=head){
        slow=slow->next;
        fast = fast->next->next;
    }
    *head1_ref = head;
    *head2_ref = slow->next;
    if(fast->next->next==head){
        fast->next->next = slow->next;
    }
    else fast->next = slow->next;
    slow->next = head;
}