class Solution{
public:
    int minValue(string str, int k){
        
        int hash[26] = {0};
        for(auto x: str){
            hash[x - 'a']++;
        }
        
        priority_queue<int> pq;
        
        for(int i = 0; i < 26; i++){
            if(hash[i] != 0){
                pq.push(hash[i]);
            }
        }
        while(!pq.empty() and k--){
            int freq = pq.top();
            pq.pop();
            pq.push(freq - 1);
        }
        
        int res = 0;
        while(!pq.empty()){
            int freq = pq.top();
            pq.pop();
            res += freq * freq;
        }
        
        return res;
    }
};