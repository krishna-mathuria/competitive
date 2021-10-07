class Solution {
  public:
    string removeChars(string string1, string string2) {
        // code here
        for(auto i : string2){
            string1.erase(remove(string1.begin(),string1.end(),i),string1.end());
        }
        return string1;
    }
};
