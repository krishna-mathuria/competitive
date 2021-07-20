#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<utility>
using namespace std;
 
const int N = 1e5;
char a[N+3];
int nxt[N+3];
int sz[N+3];
vector<pair<int,int> > ans;
int n;
 
void KMP()
{
    nxt[0] = nxt[1] = 0;
    for(int i=2; i<=n; i++)
    {
        nxt[i] = nxt[i-1];
        while(nxt[i] && a[nxt[i]+1]!=a[i])
        {
            nxt[i] = nxt[nxt[i]];
        }
        if(a[nxt[i]+1]==a[i]) nxt[i]++;
    }
}
 
int main()
{
    scanf("%s",a+1); n = strlen(a+1);
    for(int i=1; i<n+1-i; i++) swap(a[i],a[n+1-i]);
    KMP();
    for(int i=1; i<=n; i++) sz[i] = 1;
    for(int i=n; i>=1; i--) sz[nxt[i]] += sz[i];
    for(int i=n; i>0; i=nxt[i])
    {
        ans.push_back(make_pair(i,sz[i]));
    }
    printf("%d\n",ans.size());
    for(int i=ans.size()-1; i>=0; i--) printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}