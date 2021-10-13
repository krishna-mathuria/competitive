class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        int i=0;
        int j = a.size()-1;
        while(i<j){
            int mid = i + (j-i)/2;
            if(a[mid]>a[mid+1]){
                j=mid;
            }
            else{
                i=mid+1;
            }
        }
        return a[i];
        // Code here.
    }
};