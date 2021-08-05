#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,q;
        cin>>n>>q;
        vector<pair<long long,long long>> v;
        for(long long i=0;i<n;i++){
            long long a,b;
            cin>>a>>b;
            v.push_back({a,b});
        }
        sort(v.begin(),v.end());
        long long idx=0;
        for(long long i=1;i<v.size();i++)
        {
            if(v[idx].second>=v[i].first)
                v[idx].second=max(v[idx].second,v[i].second);
            else
            {
                idx++;
                v[idx] = v[i];
            }
        }
        while(q--){
            long long k;
            cin>>k;
            long long ans = -1;
            for(long long i=0;i<=idx;i++){
                if(v[i].second-v[i].first+1>=k){
                    ans = v[i].first + k -1;
                    break;
                }else{
                    k = k - (v[i].second-v[i].first +1);
                }
            }
            cout<<ans<<"\n";
        }
	}
}