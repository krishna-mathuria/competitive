long long int findMinSum(int a[], int b[], int n)
{
    // Sort both arrays
    sort(a, a+n);
    sort(b, b+n);
 
    // Find sum of absolute differences
    long long int sum= 0 ;
    for (int i=0; i<n; i++)
        sum = sum + abs(a[i]-b[i]);
 
    return sum;
}