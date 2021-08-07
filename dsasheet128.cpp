class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
       Node* temp = head;
       while(temp->next !=NULL){
            if(temp->data == -1) return 1;
            temp->data = -1;
            temp = temp->next;
       } 
       return 0;
    }
};