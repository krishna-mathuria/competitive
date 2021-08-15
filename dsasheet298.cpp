// using stack
queue<int> rev(queue<int> q)
{
    // add code here.
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    return q;
}
// using recursion 
// void rever(queue<int> &q) {
// if(q.empty()) return;
// int data = q.front();
// q.pop();
// rever(q);
// q.push(data);
// }
