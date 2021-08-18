class Solution{
    
    void generatePossibleStrings(string str, vector<string> &res, int index = 0, string curr = "")
    {
        if(index == str.size()){
            if(curr != ""){
                res.push_back(curr);
            }
            return;
        }
        generatePossibleStrings(str, res, index + 1, curr);
        generatePossibleStrings(str, res, index + 1, curr + str[index]);
    }
    public:
    vector<string> AllPossibleStrings(string str)
    {
        vector<string> res;
        generatePossibleStrings(str, res);
        sort(res.begin(), res.end());
        return res;
    }
};