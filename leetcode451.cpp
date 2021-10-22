class Solution {
public:
    string frequencySort(string s) {
                map<char,int>m;
        int n=s.size();
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        s.clear();
        multimap<int,char,greater<int>>mm;
        for(auto j:m){
            mm.insert({j.second,j.first});
        }
        for(auto x:mm){
            int n=x.first;
            while(n--){
                s+=x.second;
            }
        }
        return s;
    }
};