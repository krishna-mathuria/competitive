#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
#define pb push_back
#define F first
#define S second
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


ll n,m,lev[100005];
vll v[100005];
bool processed[100005];

main()
{
    fastio();
    cin>>n>>m;
    while(m--){
        ll a,b,c;
        cin>>a>>b>>c;
        v[a].pb({b,c});
    }

    for(ll i=1;i<=n;i++) lev[i] = 1e18;

    priority_queue<pll> q;
    q.push({0,1}); lev[1] = 0;
    while(!q.empty()){
        ll x=q.top().F,y=q.top().S; 
        q.pop();
        if (processed[y]) continue;
        processed[y] = true;
        for(auto i:v[y]){

            if(lev[i.F]>i.S-x){   

                lev[i.F]=i.S-x;              

                q.push({-lev[i.F],i.F});    
            }
        }
    }
    for(ll i=1;i<=n;i++) cout<<lev[i]<<' ';    
    cout<<'\n';
}