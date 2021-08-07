class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        Node* temp = head;
        while(temp!=NULL){
            if(temp->next !=NULL && temp->next->data==-1){
                temp->next = NULL;
                break;
            }
            temp->data = -1;
            temp = temp->next;
        }
    }
};