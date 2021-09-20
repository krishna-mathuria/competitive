#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<char> arr;
    if(n==0) {
        cout<<-1;
        return 0;
    }
    char val;
    while(cin >> val) {
      arr.push_back(val);
    }
    if(n==1){
        cout<<arr[0];
        return 0;
    }
    deque<int> nodes;
    int i=1;
    nodes.push_back(arr[i]-'0');
    for(int i=1;i<arr.size();i+=2){
        if(arr[i]!='-'){
            nodes.push_back(arr[i]-'0');
        }
        if(arr[i+1]!='-'){
            nodes.push_back(arr[i+1]-'0');
        }
        nodes.pop_front();
    }
    while(!nodes.empty()){
        cout<<nodes.front()<<" ";
        nodes.pop_front();
    }
    return 0;
    
}