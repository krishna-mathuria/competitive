// Binary Search based C++ program to find number
// of rotations in a sorted and rotated array.
#include<bits/stdc++.h>
using namespace std;

int countRotations(int arr[], int low, int high)
{
	if (high < low)
		return 0;

	if (high == low)
		return low;


	int mid = low + (high - low)/2; /*(low + high)/2;*/


	if (mid < high && arr[mid+1] < arr[mid])
	return (mid+1);

	if (mid > low && arr[mid] < arr[mid - 1])
	return mid;

	if (arr[high] > arr[mid])
	return countRotations(arr, low, mid-1);

	return countRotations(arr, mid+1, high);
}


int main()
{
	int arr[] = {15, 18, 2, 3, 6, 12};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << countRotations(arr, 0, n-1);
	return 0;
}
