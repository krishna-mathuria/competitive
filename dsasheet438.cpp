class Solution {
  public:
    int setBits(int N) {
        // Write Your Code here
        int count = 0;
        while(N != 0)
        {
            if(N % 2 != 0 || N == 1)
            {
                count++;
                N--;
            }
        if(N % 2 == 0)
            N = N/2;
        }
        return count;
    }
};