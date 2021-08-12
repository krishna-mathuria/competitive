class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies,candies+N);
        int mn=0;
        int c = N;
        for(int i=0;i<c;i++){
            mn += candies[i];
            c = c-K;
        }
        int mx=0;
        c = 0;
        for (int i=N-1;i>=c;i--){
            mx+=candies[i];
            c = c+K;
        }
        return {mn,mx};
    }
};