class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> st;
        for(auto x:emails){
            int i=0;
            string it="";
            bool fl=0;
            while(i<x.size()){
                if(x[i]=='.' && !fl) {
                    i++;
                    continue;
                }
               else if(x[i]=='+' && !fl){
                    while(x[i]!='@') i++;
                    continue;
                }
                else if(x[i]=='@'){
                    fl=1;
                    it+="@";
                    i++;
                }
                else{
                    it+=x[i];
                    i++;
                }
                
            }
            st.insert(it);
        }
        return st.size();
    }
};