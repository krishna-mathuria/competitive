#include<bits/stdc++.h>
using namespace std;
int E[1000001] , S[1000001] , F[1000001];
 
int main()
{
	string st;
	int mx = 0;
	stack<int> stk;
	
	cin>>st;
	
	for(int i=0;i<st.size();i++)
	{
		char ch = st[i];
		
		if(ch == '(')
		{
			stk.push(i);
		}
		else
		{
			if(stk.empty())
			{
				S[i] = E[i] = -1;
			}
			else
			{
				int idx = stk.top();
				stk.pop();
				
				S[i] = E[i] = idx;
				
				if(idx > 0 && st[idx-1] == ')' && S[idx-1] >= 0)
				E[i] = E[idx - 1];
				
				int l = i - E[i] + 1;
				F[l]++;
				mx = max(mx , l);
			}
		}
	}
	
	F[0] = 1;
	
	cout<<mx<<" "<<F[mx];
}
 
 