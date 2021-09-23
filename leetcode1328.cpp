class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size()==1) return "";
        int n=INT_MAX;
        if(palindrome.size()%2!=0){
            n = palindrome.size()/2;
        }
        for(int i=0;i<palindrome.size();i++){
            if(i==n) {
                continue;
            }
            if(palindrome[i]-'a'!=0){
                palindrome[i]='a';
                return palindrome;
            }
        }
        palindrome[palindrome.size()-1] = 'b';
        return palindrome;
    }
};