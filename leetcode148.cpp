class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> vec;
        ListNode* root = head;
        while(root!=NULL){
            vec.push_back(root->val);
            root=root->next;
        }
        sort(vec.begin(),vec.end());
        int i=0;
        root = head;
        while(root!=NULL){
            root->val = vec[i++];
            root=root->next;
        }
        return head;
    }
};