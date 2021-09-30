class Solution {
public:
    int nthUglyNumber(int n) {
        int arr[1700];
        arr[1]=1;
        arr[2]=2;
        arr[3]=3;
        arr[4]=4;
        arr[5]=5;
        int a=3;
        int b = 2;
        int c = 2;
        if(n<=5) return arr[n];
        for(int i=6;i<n+1;i++){
            if(arr[a]*2<=arr[b]*3 && arr[a]*2<=arr[c]*5){
                if(arr[a]*2==arr[b]*3) b++;
                if(arr[a]*2==arr[c]*5) c++;
                arr[i]=arr[a]*2;
                a++;
            }
            else if(arr[b]*3<arr[a]*2 && arr[b]*3<arr[c]*5){
                if(arr[a]*2==arr[b]*3) a++;
                if(arr[b]*3==arr[c]*5) c++;
                arr[i]=arr[b]*3;
                b++;
            }
            else{
                if(arr[c]*5==arr[b]*3) b++;
                if(arr[a]*2==arr[c]*5) a++;
                arr[i]=arr[c]*5;
                c++;
            }
        }
        return arr[n];
    }
};