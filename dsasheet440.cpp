class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        int x = a^b;
        int c=0;
        while(x>0){
            x=(x&(x-1));
            c++;
        }
        return c;
    }
};