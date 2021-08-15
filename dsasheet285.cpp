#include<bits/stdc++.h>
using namespace std;

void insert_bottom(stack<int> &st,int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    
    int temp = st.top();
    st.pop();
    insert_bottom(st,x);
    st.push(temp);
}

void reverse(stack<int> &st){
    if(st.empty()) return;
    int temp = st.top();
    st.pop();
    reverse(st);
    insert_bottom(st,temp);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverse(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}