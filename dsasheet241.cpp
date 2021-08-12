int minElements(int arr[], int n)
{
    // calculating HALF of array sum
    int halfSum = 0;
    for (int i = 0; i < n; i++)
        halfSum = halfSum + arr[i];   
    halfSum = halfSum / 2;
 
    // sort the array in descending order.
    sort(arr, arr + n, greater<int>());
 
    int res = 0, curr_sum = 0;
    for (int i = 0; i < n; i++) {
 
        curr_sum += arr[i];
        res++;
 
        // current sum greater than sum
        if (curr_sum > halfSum)        
            return res;
    }
    return res;
}