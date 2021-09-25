class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>> ans(searchWord.size());
        for(int i=0;i<searchWord.size();i++){
            string check = searchWord.substr(0,i+1);
            for(auto x: products){
                bool fl=0;
                for(int j=0;j<check.size();j++){
                    if(x[j]!=check[j]){
                        fl=1;
                        break;
                    }
                }
                if(!fl){
                    ans[i].push_back(x);
                    if(ans[i].size()==3) break;
                }
            }
        }
        return ans;
    }
};



// Solution 2

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        int start = 0, end = products.size() - 1;
        vector<vector<string>> result(searchWord.size());
        for(int i = 0; i < searchWord.size() && start <= end; i++) {
            // move pointer forward from the start index
            while(start <= end && ( products[start].size() <= i || products[start][i] != searchWord[i])) 
                ++start;
            // move pointer backward from the end index
            while(start <= end && (products[end].size() <= i || products[end][i] != searchWord[i])) --end;
            for(int j = start; j<=end && j<start+3; j++) result[i].push_back(products[j]);
        }
        return result;

    }
};