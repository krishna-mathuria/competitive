class Solution {
public:
    int titleToNumber(string columnTitle) {
        int x =0;
        for(auto y: columnTitle){
            x = (x * 26)+(y - 'A'+1);
        }
        return x;
    }
};