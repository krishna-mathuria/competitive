class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        vector<int> ans;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        for(int i=0;i<k;i++){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
