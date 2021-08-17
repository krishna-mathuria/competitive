class Solution
{
    public:
    //Function to merge k sorted arrays.
    struct Triplet{
        int val, aPos, vPos;
        Triplet(int v, int ap, int vp)
        {
            val = v;
            aPos = ap;
            vPos = vp;
        }
    };
    
    struct myCmp{
        bool operator()(Triplet &t1, Triplet &t2)
        {
            return t1.val > t2.val;
        }
    };
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        vector<int> res;
        priority_queue<Triplet, vector<Triplet>,myCmp> pq;
        for(int i=0;i<k;i++){
            Triplet t(arr[i][0],i,0);
            pq.push(t);
        }
        while(pq.empty()==false){
            Triplet curr = pq.top();
            pq.pop();
            res.push_back(curr.val);
            int ap = curr.aPos;
            int vp = curr.vPos;
            if((vp+1)<k){
                Triplet t(arr[ap][vp+1],ap,vp+1);
                pq.push(t);
            }
        }
        return res;
    }
};