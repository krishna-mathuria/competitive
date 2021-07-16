#include<bits/stdc++.h>
using namespace std;
#define MAX 100001

// Calculate seive once to avoid repetition
//check primes upto MAX number
//initialize all true
// if a number is prime then all the multiples of it are nonPrime starting from the numbers' square
// create new vector containing all the prime numbers
//push 2,then check if the index n in isPrime is true then the number n is prime

vector<int>* seive(){
    bool isPrime[MAX];
    for(int i=0;i<MAX;i++){
        isPrime[i]=true;
    }
    for(int i=2;i*i<MAX;i++){
        if(isPrime[i]){
            for(int j=i*i;j<MAX;j=j+i){
                isPrime[j]=false;
            }
        }
    }
    vector<int>* primes = new vector<int>();
    primes->push_back(2);
    for(int i=3;i<MAX;i=i+2){
        if(isPrime[i]){
            primes->push_back(i);
        }
    }
    return primes;
}
//Function to check the prime number between low and high
//first make isPrime with high-low+1 length and initialize all true
// Now for every number in primes remove the multiples in the new isPrimes
//remember 1 is not prime
//base is the first element divisible by the prime number between low and high

void printPrimes(long long low,long long high, vector<int>* & primes){
    bool isPrime[high-low+1];
    for(int i=0;i<high-low;i++){
        isPrime[i]=true;
    }
    
    for(int i=0;primes->at(i)*(long long)primes->at(i)<=high;i++){
        long long currentPrime=primes->at(i);
        long long base = (low/(currentPrime))*(currentPrime);
        if(base<low){
            base = base+ currentPrime;
        }
        for(long long j=base;j<=high;j=j+currentPrime){
            isPrime[j-low]=false;
        }
        if(base==currentPrime){
            isPrime[base-low]=true;
        }
    }
    for(int i=0;i<high-low;i++){
        if(i+low==1) continue;
        if(isPrime[i]==true){
            cout<<i+low<<endl;
        }
    }
}

//Driver Code
int main(){
    vector<int>* primes = seive();
    int t;
    cin>>t;
    while(t--){
        long long low,high;
        cin>>low>>high;
        printPrimes(low,high+1,primes);
        cout<<endl;
    }
    return 0;
}