int smallestSumSubarr(int arr[], int n)
{

    int min_ending_here = INT_MAX;

    int min_so_far = INT_MAX;
   
    for (int i=0; i<n; i++)
    {

        if (min_ending_here > 0)
            min_ending_here = arr[i];
 
        else
            min_ending_here += arr[i];

        min_so_far = min(min_so_far, min_ending_here);           
    }

    return min_so_far;
}
