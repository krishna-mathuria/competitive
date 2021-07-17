#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
const int ma = 1e5+5;
priority_queue <int> high;
priority_queue <int, std::vector<int>, std::greater<int> > low;
int fre[ma];
int main()
{
  //freopen("i.txt","r",stdin);
  //freopen("o1.txt","w",stdout);
  int q;
  cin>>q;
  int x;
  string st;
  for(int i=0;i<q;i++)
  {
   cin>>st;
   if(st[0]=='C' and st[5]=='H')
   {
      while(high.size() and fre[high.top()]==0)
      {
        high.pop();
      }
      if(high.size())
      cout<<fre[high.top()]<<endl;
      else
      cout<<"-1"<<endl;
   }
   else if(st[0]=='C' and st[5]=='L')
   {
     while(low.size() and fre[low.top()]==0)
      {
        low.pop();
      }
      if(low.size())
      cout<<fre[low.top()]<<endl;
      else
      cout<<-1<<endl;
   }
   else if(st[0]=='P')
   {
    cin>>x;
    high.push(x);
    low.push(x);
    fre[x]++;
   }
   else
   {
      while(high.size() and fre[high.top()]==0)
      {
        high.pop();
      }
      while(low.size() and fre[low.top()]==0)
      {
        low.pop();
      }
      if(high.size() and low.size())
      {
       // cout<<i<<" "<<high.top()<<" "<<low.top()<<endl;
        cout<<high.top()-low.top()<<endl;
        if(high.top() == low.top())
        {
          fre[high.top()]--;
        }
        else
        {
          fre[high.top()]--;
          fre[low.top()]--;
        }
        high.pop();
        low.pop();
      }
      else
        cout<<"-1"<<endl;
    }
  }
  return 0;
}