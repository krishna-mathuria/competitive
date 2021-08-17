class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    priority_queue<int, vector<int>, greater<int>> pq;
	    
	    for(int i=0;i<k;i++){
	        pq.push(arr[i]);
	    }
	    for(int i=k;i<n;i++){
	        if(pq.top()<arr[i]){
	            pq.pop();
	            pq.push(arr[i]);
	        }
	    }
	    vector<int> res(pq.size());
	    int index = pq.size() - 1;
	    
	    while(!pq.empty())
	    {
	        res[index--] = pq.top();
	        pq.pop();
	    }
	    
	    return res;
	}

};