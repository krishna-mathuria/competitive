bool comp(Item aa,Item bb){
    double a = (double) aa.value/aa.weight;
    double b = (double) bb.value/bb.weight;
    
    return a > b;
}
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,comp);
        double profit=0;
        for(int i=0;i<n;i++){
            if(arr[i].weight<W){
                profit+=arr[i].value;
                W = W-arr[i].weight;
            }
            else if(arr[i].weight==W){
                profit+=arr[i].value;
                W = W-arr[i].weight;
                break;
            }
            else{
                double wt = (double) arr[i].value/arr[i].weight;
                profit+= wt * W;
                break;
            }
        }
        return profit;
    }
        
};