class Solution {
public:
    int lengthOfLastWord(string s) {
        int l =0;
        bool fl=0;
        for(int i=s.size()-1;i>=0;i--){
            if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)){
                fl=1;
                l++;
            }else{
                if(fl) break;
            }
        }
        return l;
    }
};