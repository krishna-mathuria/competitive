#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


 // } Driver Code Ends

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        node *curr, *prev=NULL, *next=NULL,*first,*prevfirst;
        curr = head;
        int i=0;
        bool flag=1;
        while(curr!=NULL){
            i=0;
            first = curr;
            next = NULL;
            prev = NULL;
            while(i<k && curr!=NULL){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                i++;
            }
            if(flag){
                head = prev;
                flag = 0;
            }else {
                prevfirst->next = prev;
            }
            
            prevfirst = first;
        }
        return head;
    }
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}