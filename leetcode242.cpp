class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26]={0};
        int arr2[26]={0};
        for(auto x:s){
            arr[x-'a']++;
        }
        for(auto x:t){
            arr2[x-'a']++;
        }
        for(int i=0;i<26;i++){
            if(arr[i]!=arr2[i]){
                return false;
            }
        }
        return true;
    }
};