class Solution {
public:
    double myPow(double x, int n) {
        double d = 1.0;
        int m = n;
        for (; n; x *= x, n /= 2) 
            if (n % 2) d *= x;
        return m >= 0 ? d : 1.0 / d;
    }
};