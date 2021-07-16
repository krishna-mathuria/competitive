#include<iostream>
using namespace std;
int main(){
    int n,k;
    bool flag=0;
    cin>>n>>k;
    int arr[k+1];
    fill(arr,arr+k,1);
    int sum=k;
    for(int i=k-1; i>=0; i--){

            while(n>=sum+arr[i]){
                sum=sum+arr[i];
                arr[i]=arr[i]*2;
            }
    }
    if(sum!=n){
        cout<<"NO\n";
    }
 else{
        cout<<"YES\n";
    	for(int i=0;i<k;i++){
        cout<<arr[i]<<" ";
   	 }
	cout<<endl;
    }  
}
