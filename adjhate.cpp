#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> odd;
        vector<int> even;
        for(int i=0;i<n;i++){
            int c;
            cin>>c;
            if(c%2==0){
                even.push_back(c);
            }
            else odd.push_back(c);
        }
        if(even.size()==0 || odd.size()==0) {
            cout<<-1<<"\n";
            continue;
        }
        else{
            for(int i=0;i<odd.size();i++){
                cout<<odd[i]<<" ";
            }
            for(int i=0;i<even.size();i++){
                cout<<even[i]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}