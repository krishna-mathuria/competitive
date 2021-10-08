class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr = headA;
         ListNode* curr2 = headB;
        int a=0;
        int b=0;
        while(curr!=NULL){
            a++;
            curr=curr->next;
        }
        curr=headB;
        while(curr!=NULL){
            curr=curr->next;
            b++;
        }
        curr=headA;
        if(a>b){
            int k = a-b;
            while(k--){
                curr=curr->next;
            }
        }
        else{
            int k=b-a;
            while(k--){
                curr2=curr2->next;
            }
        }
        while(curr!=NULL && curr2!=NULL){
            if(curr==curr2){
                return curr;
            }
            curr=curr->next;
            curr2=curr2->next;
        }
        return NULL;
    }
};