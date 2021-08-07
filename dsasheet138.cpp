class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* merge(Node* a,Node* b){
        if(a == NULL)
            return b;
        
        if(b == NULL)
            return a;
        
        Node *head = NULL, *tail = NULL;
        if(a->data < b->data){
            head = tail = a;
            a = a->next;
        }
        else{
            head = tail = b;
            b = b->next;
        }
        
        while(a != NULL && b != NULL){
            if(a->data < b->data){
                tail->next = a;
                tail = a;
                a = a->next;
            }
            else{
                tail->next = b;
                tail = b;
                b = b->next;
            }
        }
        
        if(a == NULL)
            tail->next = b;
        else
            tail->next = a;
        return head;
    }
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL)
            return head;
        
        Node* slow=head;
        Node* fast=head->next;
        
        while(fast && fast->next)
        {
        slow=slow->next;
        fast=fast->next->next;
        }
        
        Node* newHead=slow->next;
        slow->next=NULL;
        
        return merge(mergeSort(head),mergeSort(newHead));
    }
};