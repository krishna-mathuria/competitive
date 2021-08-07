class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
    Node* curr = head;
    Node* prev = NULL;
    
    unordered_set<int> st;
    
    while(curr != NULL){
        if(st.find(curr->data) != st.end()){
            prev->next = curr->next;
            curr = curr->next;
        }
        
        else{
            st.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
    
    return head;
    }
};