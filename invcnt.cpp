#include<bits/stdc++.h>
using namespace std;
 

int getSum(long long BITree[], int index)
{
    long long sum = 0;
 
    while (index > 0)
    {
        sum += BITree[index];
 
        index -= index & (-index);
    }
    return sum;
}
 

void updateBIT(long long BITree[], int n, int index, int val)
{
    while (index <= n)
    {
       BITree[index] += val;
 
       index += index & (-index);
    }
}
 

void convert(int arr[], int n)
{

    int temp[n];
    for (int i=0; i<n; i++)
        temp[i] = arr[i];
    sort(temp, temp+n);
 
    for (int i=0; i<n; i++)
    {
        arr[i] = lower_bound(temp, temp+n, arr[i]) - temp + 1;
    }
}
 
long long int getInvCount(int arr[], int n)
{
    long long int invcount = 0;

    convert(arr, n);

    long long BIT[n+1];
    for (int i=1; i<=n; i++)
        BIT[i] = 0;
 
    for (int i=n-1; i>=0; i--)
    {
        invcount += getSum(BIT, arr[i]-1);
 
        updateBIT(BIT, n, arr[i], 1);
    }
 
    return invcount;
}
 
int main()
{

    
    int arr[200500];
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	scanf("%d",arr+i);	
	}
    cout << getInvCount(arr,n)<<endl;
    }
    return 0;
}