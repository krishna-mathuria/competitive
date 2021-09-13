class Solution {
public:
    long long arr[38];
    long long f(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        if(arr[n]!=0)
            return arr[n];
        return arr[n]= f(n-1)+f(n-2)+f(n-3);
    }
    int tribonacci(int n) {
        return f(n);   
    }
};