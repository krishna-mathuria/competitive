class Solution {
public:
    int divide(int dividend, int divisor) { // dividend / divisor
        
        int ans = 0;

        // Handle special cases
        if (divisor == INT_MIN)
            if (dividend == divisor) return 1;
            else return 0;
        
        if (dividend == INT_MIN)
            if (divisor == 1) return INT_MIN;
            else if (divisor == -1) return INT_MAX;
            else dividend += abs(divisor), ans++; // INT_MIN + abs(divisor) / abs(divisor) = 1 + INT_MIN / abs(divisor)

        // find the sign of the answer
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        
        // making both dividend and divisor positive
        dividend = abs(dividend), divisor = abs(divisor);
        
        // main code
        while(dividend >= divisor) { 
            int t=1; // multiplier by default 1 since (dividend >= divisor)
            int curr_dvs=divisor;
            int curr_dvd=dividend >> 1;
            
            while (curr_dvd >= divisor){
                curr_dvs = curr_dvs << 1;
                t = t << 1;
                curr_dvd = curr_dvd>>1;
            }

            dividend -= curr_dvs;
            ans += t;
        }
        return sign > 0 ? ans : -ans;
    }
};