class Solution{
  public:
    /* The below method print the required sum of polynomial
    p1 and p2 as specified in output  */
    Node* addPolynomial(Node *p1, Node *p2)
    {
        //Your code here
        if(!p1){
            return p2;
        }
        if(!p2){
            return p1;
        }
        if(p1->pow==p2->pow){
            p1->coeff=p1->coeff+p2->coeff;
            p1->next=addPolynomial(p1->next,p2->next);
            return p1;
        }
        if(p1->pow>p2->pow){
            p1->next=addPolynomial(p1->next,p2);
            return p1;
        }
        if(p1->pow<p2->pow){
            p2->next=addPolynomial(p1,p2->next);
            return p2;
        }
    }
};
