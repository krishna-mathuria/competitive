class Solution {
public:
    int guessNumber(int n) {
        int lo = 1;
        int hi = n;
        while(lo<=hi){
            int mid = hi - (hi-lo)/2;
            int x=guess(mid);
            //cout<<x;
            if(x==-1){
                hi=mid-1;
            }
            else if(x==1){
                lo=mid+1;
            }
            else return mid;
        }
        return -1;
    }
};