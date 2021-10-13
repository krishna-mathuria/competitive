class Solution {
public:
    
    string s ;
    unordered_map<string,int> umap;
    vector<string> result;
    
    void rec( int start  , string list ){
        if( start == s.length() ){
            list.pop_back();
            result.push_back( list );
            return;
        }
        
        string currstring = "" , temp;
        for( int i = start ; i < s.length() ; i++ ){
            currstring += s[i];
            if( umap.find(currstring) != umap.end() ){
                temp = list;
                list += currstring ;
                list += " ";
                rec(i+1, list );
                list = temp;
            }
            
        }
        
        return ;
        
    }
    
    vector<string> wordBreak(string s1, vector<string>& wordDict) {
        s = s1;
        for( string word : wordDict ){
            umap[word] = 1;
        }
        
        rec( 0, "" );
        return result;
    }
};