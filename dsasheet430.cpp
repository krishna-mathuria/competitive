class Solution{
	public:
    long long getCount(int N)
    {
        long long a[] = {1,1,1,1,1,1,1,1,1,1};
        for(int i = 1; i < N; i++){
            long long b[10];
            b[0] = a[0] + a[8];
            b[1] = a[1] + a[2] + a[4];
            b[2] = a[1] + a[2] + a[3] + a[5];
            b[3] = a[2] + a[3] + a[6];
            b[4] = a[1] + a[4] + a[7] + a[5];
            b[5] = a[2] + a[4] + a[5] + a[6] + a[8];
            b[6] = a[3] + a[5] + a[6] + a[9];
            b[7] = a[4] + a[7] + a[8];
            b[8] = a[5] + a[7] + a[8] + a[9] + a[0];
            b[9] = a[6] + a[8] + a[9];
            memcpy(a,b,10*sizeof(long long));
        }
        return accumulate(a, a + 10, 0LL);
    }
};