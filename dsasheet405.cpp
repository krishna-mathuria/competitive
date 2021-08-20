class Solution{
public:	
	int maxSubstring(string S)
	{
	    int start;
	    for(int i=0;i<S.size();i++){
	        if(S[i]=='0') {
	            start = i;
	            break;
	        }
	        if(i==S.size()-1 && S[i]!='0') return -1;
	    }
	    int n0=0,n1=0,ans=0;
	    for(int i=start;i<S.size();i++){
            if(S[i]=='0') n0++;
            else n1++;
            if(n0<n1){
                n0=0;
                n1=0;
            }
            ans = max(n0-n1,ans);
	    }
	    return ans;
	}
};