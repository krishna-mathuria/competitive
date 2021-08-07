class Solution
{
    public:
//function to reverse linked list
    Node *reverse(Node *head)
    {
        Node *prev=NULL, *curr=head, *nxt=NULL;
        while(curr!=NULL)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
//recursive function
    Node *recursiveadd(struct Node* first, struct Node* second)
    {
        if(first==NULL) return second;
        if(second==NULL) return first;
        
        int sum=first->data+second->data;
        Node *temp=new Node(sum%10);
        temp->next=recursiveadd(first->next,second->next);
        if(sum>=10) temp->next=recursiveadd(temp->next,new Node(1));
        return temp;
    }
//Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first=reverse(first);
        second=reverse(second);
        
        return reverse(recursiveadd(first,second));
    }
};
