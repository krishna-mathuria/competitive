class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast, *slow;
        fast=head;
        slow = head;
        while(fast->next!=NULL){
            slow = slow->next;
            if(fast->next->next==NULL) fast=fast->next;
            else fast = fast->next->next;
        }
        return slow;
    }
};