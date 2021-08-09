class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node * even = new Node(0), * odd = new Node (0), * e =even, * o = odd ;
        while(head){
        if (head -> data%2== 1)o -> next = head, o = o -> next ;
        else e -> next = head, e = e -> next ;
        head = head -> next ;
        }
        if (e) e -> next = odd -> next ;
        if (o) o -> next = nullptr ;
        return even -> next ;
    }
};