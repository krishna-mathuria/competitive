#include <iostream>
#include <stack>
using namespace std; 
int main(){
    int n,count{};
    cin>>n;
    stack<int> s1;
    stack<int> s2;
    int arr[n]={};
    for (int i{};i<n;i++)
        cin>>arr[i];
    s1.push(arr[0]);
    for (int i{};i<n;i++){
        if (arr[i]<s1.top())
            count+=1;
        else
        s1.push(arr[i]);
    }
    s2.push(arr[n-1]);
    for (int i{n-1};i>=0;i--){
        if (arr[i]<s2.top())
            count+=1;
        else
            s2.push(arr[i]);
    }
    cout<<count;
}