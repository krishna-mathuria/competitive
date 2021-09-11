class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* root = head,*nxt=NULL,*prev=NULL,*prevLast = NULL;
        if(root==NULL || root->next==NULL) return root;
        head = head->next;
        while(root!=NULL && root->next!=NULL){
            nxt = root->next;
            prev = root;
            prev->next = nxt->next;
            nxt->next = prev;
            if(prevLast!=NULL){
                prevLast->next = nxt;
                prevLast = prev;
            }else{
                prevLast = prev;
            }
            root = root->next;
        }
        return head;
    }
};