#include <bits/stdc++.h>
using namespace std;

char getMaxCountChar(const vector<int>& count)
{
    int max = 0;
    char ch;
    for (int i = 0; i < 26; i++) {
        if (count[i] > max) {
            max = count[i];
            ch = 'a' + i;
        }
    }
 
    return ch;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int n=s.size();
	    vector<int> count(26, 0);
        for (auto ch : s)
        count[ch - 'a']++;
	    char ch_max = getMaxCountChar(count);
        int maxCount = count[ch_max - 'a'];
	    if(maxCount>(n+1)/2) 
	        cout<<0<<endl;
	    else cout<<1<<endl;
	        
	    
	}
	return 0;
}