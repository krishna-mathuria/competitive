class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> mp;
        for(int i=0;i<chars.size();i++){
         mp[chars[i]]++;   
        }
        int count=0;
        for(auto word: words){
            unordered_map<char,int> mp2;
            for(auto x: word){
                mp2[x]++;
            }
            for(auto x:mp2){
                auto y = mp.find(x.first);
                if(y!=mp.end()){
                    if(x.second>y->second){
                        count -=word.size();
                        break;
                    }
                }else{
                        count -=word.size();
                        break;
                }
            }
            //cout<<count<<" ";
            count+=word.size();
        }
        return count;
    }
};