class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int arr[26]={0};
        for(int i=0;i<text.size();i++){
            arr[text[i]-'a']++;
        }
        int count=0;
        while(arr[1]>0 && arr['l'-'a']>1 && arr[0]>0 && arr['o'-'a']>1 && arr['n'-'a']>0){
            count++;
            arr[1]--;
            arr['l'-'a']-=2;
            arr[0]--;
            arr['n'-'a']--;
            arr['o'-'a'] -=2;
        }
        return count;
    }
};