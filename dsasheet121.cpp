#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1,n2;
    while(true){
        cin>>n1;
        if(n1==0) break;
        int arr1[n1+1],sum1[n1+1];
        for(int i=0;i<n1;i++){
            cin>>arr1[i];
            if(i==0) sum1[i]=arr1[i];
            else sum1[i] = sum1[i-1]+ arr1[i];
        }
        arr1[n1]=10005;
        sum1[n1]=sum1[n1-1] + 10005;
        cin>>n2;
        int arr2[n2+1],sum2[n2+1];
        for(int i=0;i<n2;i++){
            cin>>arr2[i];
            if(i==0) sum2[i]=arr2[i];
            else sum2[i] = sum2[i-1]+  arr2[i];
        }
        arr2[n2]=10005;
        sum2[n2]=sum2[n2-1] + 10005;
        int i=0,j=0;
        int previ = 0;
        int prevj = 0;
        long long ans=0;
        while(i<=n1 && j<=n2){
            if(arr1[i]==arr2[j]){
                ans += max(sum1[i]-previ,sum2[j]-prevj);
                previ = sum1[i];
                prevj = sum2[j];
                i++;
                j++;
            }
            else if(arr1[i]>arr2[j]){
                j++;
            }
            else if(arr1[i]<arr2[j]){
                i++;
            }
        }
        cout<<ans-10005<<"\n";
    }
}