class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node* curr =head;
        int arr[3]={0,0,0};
        while(curr!=NULL){
            arr[curr->data]++;
            curr=curr->next;
        }
        curr=head;
        while(curr!=NULL){
            while(arr[0]--){
                curr->data = 0;
                curr = curr->next;
            }
            while(arr[1]--){
                curr->data = 1;
                curr = curr->next;
            }
            while(arr[2]--){
                curr->data = 2;
                curr = curr->next;
            }
        }
        return head;
    }
};
