    bool ispar(string x)
    {
        // Your code here
        stack<int> st;
        if(x[0]==']' || x[0]=='}' || x[0]==')') return false;
        st.push(x[0]);
        for(int i=1;i<x.length();i++){
            if(x[i]=='[' || x[i]=='{' || x[i]=='('){
                st.push(x[i]);
            }
            else{
                if(!st.empty() && x[i]=='}' && st.top()=='{') st.pop();
                else if(!st.empty() && x[i]==']' && st.top()=='[') st.pop();
                else if(!st.empty() && x[i]==')' && st.top()=='(') st.pop();
                else return false;
            }
        }
        if(st.empty()) return true;
        else return false;
    }