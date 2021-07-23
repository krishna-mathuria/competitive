#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;
int n,m,q;
# define INF 1e18
long long A[502][502];

void solve(){
    for(long long k=1;k<=n;k++){
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=n;j++){
                A[i][j] = min(A[i][j],A[i][k]+A[k][j]);
                A[j][i] = min(A[j][i],A[i][k]+A[k][j]);
            }
        }
    }
}

int main(){
    cin>>n>>m>>q;

    for(long long i=0;i<n+2;i++){
        for(long long j=0;j<n+2;j++){
            if(i==j){
                A[i][j]=0;
            }else{
                A[i][j]=INF;
                A[j][i]=INF;
            }
    }
    }
    for(long long i=0;i<m;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        if(A[a][b]>c){
            A[a][b]=c;
            A[b][a]=c;
        }
    }
    solve();
   while(q--){
    long long query1,query2;
    cin>>query1>>query2;
    if(A[query1][query2]==INF){
        cout<<-1<<"\n";
    }else{
    cout<<A[query1][query2]<<"\n";
   }
   }
}