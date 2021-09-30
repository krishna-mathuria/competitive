class Solution {
private:
    unordered_map<string, vector<pair<string, double>>> children;                              
    
    pair<bool, double> search(string& a, string& b, unordered_set<string>& visited, double val) {
        if (visited.count(a) == 0) {
            visited.insert(a);                                                                  
            for (auto p : children[a]) {
                double temp = val * p.second;                                                  
                if (p.first == b) { return make_pair(true, temp); }                             
                
                auto result = search(p.first, b, visited, temp);
                if (result.first) { return result; }
            }
        }
        return make_pair(false, -1.0);
    }
    
public:
     vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        
        for (int i = 0; i < equations.size(); i++) {
            children[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));      
            children[equations[i][1]].push_back(make_pair(equations[i][0], 1.0 / values[i]));
        }
        
        for (auto p : queries) {
            unordered_set<string> visited;                                                       
            ans.push_back(p[0] == p[1] && children.count(p[0]) ? 1.0 : search(p[0], p[1], visited, 1.0).second);
        }
        
        return ans;
    }
};
