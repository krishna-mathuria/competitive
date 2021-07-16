#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define ll  long long

int main()
{
    ll n,i,k;
    cin>>n>>k;
        ll v[k+1];
        fill(v,v+k,1);
        ll sum=k;
        for(i=k-1; i>=0; i--)
        {
            while(sum+v[i]<=n)
            {
                sum+=v[i];
                v[i]*=2;
            }
        }
        if(sum!=n)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            for(i=0;i<k;i++)cout<<v[i]<<" ";
            cout<<endl;
        }
}
 