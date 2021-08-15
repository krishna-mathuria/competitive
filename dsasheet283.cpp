class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int>st;
        for(int i=0;i<S.size();i++){
            if(S[i]=='*' || S[i]=='-' || S[i]=='+' || S[i]=='/'){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                if(S[i]=='*') st.push(x*y);
                else if(S[i]=='+') st.push(x+y);
                else if(S[i]=='-') st.push(y-x);
                else if(S[i]=='/') st.push(y/x);
            }else{
                st.push((int)S[i]-'0');
            }
        }
        return st.top();
    }
};