#include<bits/stdc++.h>
using namespace std;

void subArraySum(int arr[],int n,int sum){
    int curr =0;
    int i=0;
    int j=0;
    for(i=0;i<n;i++){
        curr=curr+arr[i];
        if(curr==sum){
            cout<<j<<" "<<i;
            return;
        }
        else if(curr>sum){
            break;
        }
    }
    while(i<n){
        while(curr>sum){
            curr = curr - arr[j];
            j++;
            if(curr==sum){
                cout<<j<<" "<<i;
                return;
            }
        }
        while(curr<sum){
            i++;
            curr+=arr[i];
            if(curr==sum){
                cout<<j<<" "<<i;
                return;
            }
        }
        
    }
}

int main()
{
    int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 23;
    subArraySum(arr, n, sum);
    return 0;
}