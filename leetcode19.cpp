class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k=n;
        ListNode* fast = head;
        ListNode* slow=head;
        while(k--){
            fast=fast->next;
        }
        if(fast==NULL) return head->next;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(slow->next!=NULL)
        slow->next = slow->next->next;
        else if(slow==head){ return slow->next;}
        else{
            slow->next=NULL;
        }
        return head;
    }
};