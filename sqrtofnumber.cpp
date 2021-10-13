long long int floorSqrt(long long int x) 
{
    // Your code goes here   
    long long i=1;
    for(i=0;i*i<=x;i++){
    if(i*i==x) return i;
    }
    return i-1;
}