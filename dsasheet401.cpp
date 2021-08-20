bool cmp(struct val a, struct val b){
    return a.second<b.second;
}
int maxChainLen(struct val p[],int n)
{
//Your code here
    sort(p,p+n,cmp);
    vector<int> v;
    v.push_back(p[0].second);
    for(int i=1;i<n;i++){
        if(p[i].first > v.back()){
            v.push_back(p[i].second);
        }
        else{
            int temp = lower_bound(v.begin(),v.end(),p[i].second) -v.begin(); 
            v[temp] = p[i].second;
        }
    }
    return v.size();
}