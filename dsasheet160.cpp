int getNthFromLast(Node *head, int n)
{
       // Your code here
    Node*front=head;
    Node*rear=head;
    int num=0;
    while(front)
    {
    if(++num>n)
        rear=rear->next;
    front=front->next;
    }
    if(n>num)
    return -1;
    else return rear->data;
}