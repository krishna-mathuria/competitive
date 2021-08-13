class Solution{
  public:
    bool partition(vector<int> p, int A[], int r, int s)
    {
        if(r<0)
        return true;
        
        int x = A[r];
        r--;
        
        for(int i=0;i<p.size();i++)
        {
            if(p[i]+x <= s)
            {
                p[i] += x;
                
                if(partition(p, A, r, s))
                return true;
                
                p[i] -= x;
            }
            
            if(p[i] == 0)
            break;
        }
        
        return false;
    }
    
    bool isKPartitionPossible(int A[], int N, int K)
    {
         //Your code here
         
         sort(A, A+N);
         
         int sum=0;
         for(int i=0;i<N;i++)
         sum += A[i];
         
         if(sum % K !=0)
         return false;
         
         int r = N-1;
         int s = sum/K;
         
         if(A[N-1] > s)
         return false;
         
         int n = K;
         
         while(A[r] == s)
         {
             r--;
             K--;
         }
         
         vector<int> p;
         
         for(int i=0;i<K;i++)
         p.push_back(0);
         
         return partition(p, A, r, s);
    }
};