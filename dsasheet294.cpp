void StackQueue :: push(int x)
{
    // Your Code
    s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
        // Your Code    
        if(s1.size()==0) return -1;
        if(s1.size()==1){
            int s = s1.top();
            s1.pop();
            return s;
        }
        
        while(s1.size()!=1){
            s2.push(s1.top());
            s1.pop();
        }
        int val  = s1.top();
        s1.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return val;
}