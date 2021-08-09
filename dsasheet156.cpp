class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * merge(Node *a,Node *b){
        Node *temp = new Node(0);
        Node *res = temp;
        while(a!=NULL && b!=NULL){
            if(a->data<b->data){
                temp->next=a;
                temp = temp->next;
                a = a->next;
            }
            else{
                temp->next=b;
                temp = temp->next;
                b = b->next;
            }
        }
        if(a) temp->next = a;
        else temp->next = b;
        return res->next;
    }
    Node * mergeKLists(Node *arr[], int K)
    {
            Node *head = new Node(0);
            if(K==1) return arr[0];
            for(int i=0;i<K;i++){
                head = merge(head,arr[i]);
            }
           return head->next;
    }
};