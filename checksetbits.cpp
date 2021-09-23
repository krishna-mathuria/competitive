class Solution{
public:
    int isBitSet(int N){
        // code here 
        while(N%2==1){
            if(N==1) return 1;
            N=N/2;
        }
        return 0;
    }
};
