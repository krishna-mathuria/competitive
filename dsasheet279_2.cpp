int _stack :: getMin()
{
   //Your code here
   if(s.empty()) return -1;
   return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
   int x;
   if(s.empty()) return -1;
   else{
       if(s.top()>=minEle){
           x = s.top();
           s.pop();
       }
       else if(s.top()<minEle){
           x=minEle;
           minEle = 2 * minEle - s.top();
           s.pop();
        }
        return x;
    }
}

/*push element x into the stack*/
void _stack::push(int a)
{
   //Your code here
   	if(s.size()==0){
        s.push(a);
        minEle = a;
	}
	else{
        if(a>=minEle)
            s.push(a);
        else if(a<minEle){
            s.push(2*a-minEle);
            minEle = a;
        }
    }
}