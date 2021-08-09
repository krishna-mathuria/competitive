long long  multiplyTwoLists (Node* l1, Node* l2)
{
  //Your code here
  long long mod = 1000000007;
    Node *c1=l1,*c2=l2;
    long long n,m;
    n=c1->data;
    m=c2->data;
    while(c1->next!=NULL){
      c1=c1->next;
      n = ((10*n) + c1->data)%mod; 
    }
    while(c2->next!=NULL){
      c2=c2->next;
      m = ((10*m) + c2->data)%mod; 
    }
    return (n*m)%mod;
}