class Solution{
  public:
  
    int tour(petrolPump p[],int n)
    {
       int sum=0,a[n];
       for(int i=0;i<n;i++)
       {
           a[i]=p[i].petrol-p[i].distance;
           sum+=a[i];
       }
       if(sum<0)
       return -1;
       sum=0;
       int f=0;
       for(int i=0;i<n;i++)
       {
           sum+=a[i];
           if(sum<0)
           {
               f=i+1;
               sum=0;
           }
       }
       return f;
    }
};