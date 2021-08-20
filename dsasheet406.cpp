class Solution{
  public:
  
    int minJumps(int arr[], int n){
        
        int jumps=0,steps=0,maxReach =0;
        for(int i=0;i<n-1;i++){
            maxReach = max(maxReach,i+arr[i]);
            if(i==steps){
                jumps++;
                steps = maxReach;
            }
            if(steps>=n-1) break;
        }
        if(steps<n-1) return -1;
        return jumps;
}