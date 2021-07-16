#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    for(int z=0;z<t;z++){
        int n,b,a;
        cin>>n;
        cin>>b>>a;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
		double max_ans=0;
		for(int k=a;k<=b;k++){
			long long sum=0;
			for(int i=0;i<k;i++){
				sum=sum+arr[i];
			}
			max_ans=max(max_ans,(double)sum/k);
			int i=0;int j=k-1;
			while(j<n-1){
				sum-=arr[i];
				i++;
				j++;
				sum+=arr[j];
				max_ans=max(max_ans,(double)sum/k);
			}
		}
		cout<<fixed<<setprecision(7)<<max_ans<<endl;
	}
    }

//first store the array
//start loop from a till b through k
//first take avg of first k digits and then traverse and keep changing maximum
//then change the value of k and repeat