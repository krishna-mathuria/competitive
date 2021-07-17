#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define si(x) scanf("%d", &x)
#define sc(x) scanf("%c", &x)
#define sl(x) scanf("%lld", &x)
#define pl(x) printf("%lld\n", x)
#define pi(x) printf("%d\n", x)
#define gu getchar_unlocked
#define pu putchar_unlocked
#define setbits __builtin_popcountll
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define speed ios::sync_with_stdio(false)

priority_queue < pair < ll, ll > > q;     // maintain the information of the largest gap
map < ll, int > m;
map < ll, int > :: iterator it;

int main(){
	ll n;
	sl(n);
	int k, i;
	si(k);
	string s;
	cin>>s;
	q.push(mp(n, (ll)-1));
	for(i = 1; i <= k; i++){
		// place the ith person
		pair < ll, ll > P = q.top();
		q.pop();
		if(P.first % 2 == 1){        // seat preference does not matter - odd number of seats
			ll start = -P.second;
			ll end = start + P.first - 1;
			ll pos = (start + end) / 2;
			m[pos] = i;
			ll size1 = pos - start;
			ll size2 = end - pos;
			q.push(mp(size1, -start));
			q.push(mp(size2, -(pos + 1)));
		}
		else{                      // seat preference matters - no middle seat
			ll start = -P.second;
			ll end = start + P.first - 1;
			ll pos = (start + end) / 2;
			if(s[i - 1] == 'R'){
				pos++;
			}
			m[pos] = i;
			ll size1 = pos - start;
			ll size2 = end - pos;
			q.push(mp(size1, -start));
			q.push(mp(size2, -(pos + 1)));
		}
	}
	int q;
	si(q);
	while(q--){
		ll pos;
		sl(pos);
		if(m.find(pos) != m.end()){
			pi(m[pos]);
		}
		else{
			pi(-1);
		}
	}
}