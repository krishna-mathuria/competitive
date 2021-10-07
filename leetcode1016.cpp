class Solution {
public:
    string getbits(int num){
        string temp = "";
        while(num){
            temp += to_string(num%2);
            num = num/2;
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
    bool queryString(string s, int n) {
        for(int i = 1 ; i <= n ; i++){
            if(s.find(getbits(i)) == string::npos)
                return false;
        }
        return true;
    }
};