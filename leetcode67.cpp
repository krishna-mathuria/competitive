class Solution {
public:
    string ans="";
    string addBinary(string a, string b) {
        if(a.size()>b.size()){
            addBinary(b,a);
        }else{
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i=0;
        bool carry=false;
        for(i=0;i<a.size();i++){
            if(a[i]=='1'){
                if(b[i]=='1'){
                    if(carry)
                        ans+="1";
                    else {
                        ans+="0";
                        carry=true;
                    } 
                }
                else{
                    if(carry) {
                        ans+="0";
                    }
                    else{
                        ans+="1";
                    }
                }
            }
            else{
                if(b[i]=='1'){
                    if(carry){
                        ans+="0";
                    }
                    else{
                        ans+="1";
                    }
                }
                else{
                    if(carry) {
                        ans+="1";
                        carry= false;
                    }
                    else ans+="0";
                }
            }
        }
        while(i<b.size()){
            if(carry && b[i]=='1'){
                ans+="0";
            }
            else if(carry && b[i]=='0'){
                ans+="1";
                carry=false;
            }
            else{
                ans+=b[i];
            }
            i++;
        }
        if(carry){
            ans+="1";
        }
        reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};