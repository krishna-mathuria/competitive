vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
    
    vector<long long> v;
    for(int i=0;i<N;i++){
        if(A[i]<0){
            v.push_back(i);
        }
    }
    v.push_back(N+1);
    vector<long long> res;
    int s=0;
    for(int i=0;i<=N-K;i++){
        while(s<v.size() && v[s]<i){
            s++;
        }
        if(v[s]>K+i-1){
            res.push_back(0);
        }
        else{
            res.push_back(A[v[s]]);
        }
    }
    return res;                                       
 }