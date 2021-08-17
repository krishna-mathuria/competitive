class Solution{
    public:
    void maxHeapify(vector<int> &arr, int n, int idx){
        if (idx >= n)
            return;
        int l = 2 * idx + 1;
        int r = 2 * idx + 2;
        int max;
        if (l < n && arr[l] > arr[idx])
            max = l;
        else
            max = idx;
        if (r < n && arr[r] > arr[max])
            max = r;
    
        if (max != idx) {
            swap(arr[max], arr[idx]);
            maxHeapify(arr, n, max);
        }
    }
  
    void buildMaxHeap(vector<int> &arr, int n){
        for (int i = n / 2 - 1; i >= 0; i--)
            maxHeapify(arr, n, i);
    }
  
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int>res;
        for(int i=0;i<n;i++){
            res.push_back(a[i]);
        }
        for(int i=0;i<m;i++){
            res.push_back(b[i]);
        }
        buildMaxHeap(res,n+m);
        return res;
    }
};