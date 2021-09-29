class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=head;
        while(temp!=NULL && temp->next!=NULL){
            prev = temp;
            if(temp->val==temp->next->val){
                while(temp->next && temp->val == temp->next->val){
                    temp=temp->next;
                }
                prev->next = temp->next;
            }
            temp = temp->next;
        }
        return head;
    }
};