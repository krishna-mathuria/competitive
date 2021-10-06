class Solution {
public:
    bool isPalindrome(string s) {
        string t="";
        for(auto x:s){
            x = tolower(x);
            if(x-'a'<26 && x-'a'>=0){
                t+=x;
            }
            else if(x-'0'<10 && x-'0'>=0){
                t+=x;
            }
        }
        int i=0;
        int j = t.size()-1;
        while(i<=j){
          if(t[i]!=t[j]){
              return false;
          } 
            i++;
            j--;
        }
        return true;
    }
};