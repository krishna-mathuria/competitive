class Solution{
public:	
	
	string firstAlphabet(string S)
	{
	    // Your code goes here
	    bool fl=1;
	    string ans="";
	    for(int i=0;i<S.size();i++){
	        if(S[i]>='a' && S[i]<='z'){
	            if(fl){
	                ans+=S[i];
	                fl=0;
	            }
	            continue;
	        }
	        else{
	            fl=1;
	        }
	    }
	    return ans;
	    
	}
};