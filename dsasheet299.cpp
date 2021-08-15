queue<int> modifyQueue(queue<int> q, int k)
{
    //add code here.
    stack<int> s;
    queue<int> q2;
    while(k--){
        s.push(q.front());
        q.pop();
    }
    while(!q.empty()){
        q2.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    while(!q2.empty()){
        q.push(q2.front());
        q2.pop();
    }
    return q;
}