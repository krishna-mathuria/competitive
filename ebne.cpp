#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,counter;
        char one,two;
        bool flag=0;
        string s;
        cin>>n;
        cin>>s;
        for(int i=0;i<n;i++){
            counter=i;
            if(s[i]=='1' || s[i]=='3' || s[i]=='5' || s[i]=='7' || s[i]=='9'){
                one=s[i];
                break;
            }
        }
        for(int i=counter+1;i<n;i++){
            if(s[i]=='1' || s[i]=='3' || s[i]=='5' || s[i]=='7' || s[i]=='9'){
                two=s[i];
                flag=1;
                break;
            }
        }
        if(flag){
        cout<<one<<two<<'\n';
        }
        else{
            cout<<-1<<'\n';
        }
    }
    return 0;
}