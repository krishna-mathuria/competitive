#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, k;
    int n, m, t;
    int q, r;

    cin>>t;

    while(t--)
    {
        set<int> s;
        cin>>n;

        s.insert(0);
        k = sqrt(n) + 1;
        for(i = 1; i <= k; i++)
        {
            s.insert(n / i);
            j = n / i;
            if(j)
                s.insert(n / j);
        }

        cout<<s.size()<<"\n";
        for(int e : s)
            cout<<e<<" ";
        cout<<"\n";
    }



    return 0;
}