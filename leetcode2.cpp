class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode preHead(0), *p = &preHead;
        int carry = 0;
        while(l1!=NULL || l2!=NULL || carry!=0){
            if (l1){
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2){ 
                carry += l2->val;
                l2 = l2->next;
            }
             p->next = new ListNode(carry % 10);
            carry /= 10;
            p = p->next;
        }
        return preHead.next;
    }
};