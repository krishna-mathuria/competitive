void rotate(int lru[],int j,int C){
    int temp = lru[j];
    for(int i=j;i<C-1;i++){
        lru[i] = lru[i+1];
    }
    lru[C-1] = temp;
}

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        int lru[C];
        memset(lru,-1,sizeof(lru));
        int ans=0;
        bool found = 0;
        for(int i=0;i<N;i++){
            found = 0;
            for(int j=0;j<C;j++){
                if(lru[j]==pages[i]){
                    found = 1;
                    rotate(lru,j,C);
                    break;
                }
            }
            if(!found){
                ans++;
                for(int j=0;j<C-1;j++){
                    lru[j]=lru[j+1];
                }
                lru[C-1] = pages[i];
            }

        }
        return ans;
    }
};
