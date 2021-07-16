#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int count;
vector<pair<long long, long long>> swapped;
void swap(int *xp, int *yp,int min_idx,int i)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    if(min_idx!=i){
    count++;
    swapped.push_back(std::make_pair(i,min_idx));
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i],min_idx,i);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selectionSort(arr,n);
    cout<<count<<'\n';
    for(int i=0;i<swapped.size();i++){
        cout<<swapped[i].first<<" "<<swapped[i].second<<'\n';
    }
    return 0;
}





