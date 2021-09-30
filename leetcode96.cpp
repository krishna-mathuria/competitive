class Solution {
public:
    int64_t numTrees(int n) {
        return n ? numTrees(n-1)*2*(2*n-1)/(n+1) : 1;
    }
};