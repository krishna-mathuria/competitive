class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        Node *prev=NULL,*curr,*next=NULL;
        curr=head;
        while(curr!=NULL){
            next=curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        curr = prev;
        next = prev;
        int mx=curr->data;
        curr = curr->next;
        while(curr!=NULL){
            if(curr->data>=mx){
                prev->next=curr;
                mx = curr->data;
                prev=prev->next;
                curr = curr->next;
            }
            else{
                curr=curr->next;
            }
        }
        prev->next = NULL;
        curr = next;
        prev=NULL;
        next = NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
};