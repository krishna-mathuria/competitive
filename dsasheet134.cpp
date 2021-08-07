class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node *curr,*prev=NULL,*next=NULL;
        curr = head;
        while(curr!=NULL){
            next = curr->next;
            curr->next= prev;
            prev = curr;
            curr = next;
        }
        curr = prev;
        head = curr;
        if(curr->data!=9){
            curr->data++;
        }
        else{
            while(curr->data==9){
                curr->data=0;
                prev = curr;
                curr=curr->next;
                if(curr==NULL){
                    Node* new_node = new Node(1);
                    new_node->data = 1;
                    prev->next = new_node;
                    new_node->next = NULL;
                    curr = prev->next;
                }else if(curr->data!=9){
                    curr->data++;
                    break;
                }
                
            }
        }
        prev=NULL;
        next = NULL;
        curr=head;
        while(curr!=NULL){
            next = curr->next;
            curr->next= prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
};