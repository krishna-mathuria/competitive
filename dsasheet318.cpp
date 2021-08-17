class Solution {
public:
    string reorganizeString(string s) {
        int arr[26] = {0};
        int mx=0;
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
            if(arr[s[i]-'a']>arr[mx]) mx = (s[i]-'a');
        }

        if(2*arr[mx]-1>s.size()) return "";
        int i=0;
        while(arr[mx]){
           s[i] = ('a' + mx);
            arr[mx]--;
            i=i+2;
        }
        for(int j=0;j<26;j++){
            while(arr[j]){
                if(i>=s.size()) i=1;
                s[i] = ('a'+ j);
                arr[j]--;
                i=i+2;
            }
            
        }
        return s;
    }
};