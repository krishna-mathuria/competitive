class Solution{
public:
    int memo[202][202][2];
    int func(string &S,int i,int j,bool isTrue){
        if(memo[i][j][isTrue]==-1){
            int count=0;
            int res = INT_MIN;
            if(i>j) res = false;
            if(i==j){
                if(isTrue==true) res = (S[i]=='T');
                else res =(S[i]=='F');
            }
            for(int k=i+1;k<j;k+=2){
                int lt = func(S,i,k-1,true);
                int lf = func(S,i,k-1,false);
                int rt = func(S,k+1,j,true);
                int rf = func(S,k+1,j,false);
                if(S[k]=='|'){
                    if(isTrue==true)
                        count+=lt*rf + lf * rt + lt*rt;
                    else
                        count+=lf*rf;
                }
                else if(S[k]=='&'){
                    if(isTrue==true)
                        count+=lt*rt;
                    else 
                        count +=lf*rt + lt*rf + lf*rf;
                }
                else if(S[k]=='^'){
                    if(isTrue==true)
                        count+=lt*rf + lf*rt;
                    else
                        count +=lt*rt + lf*rf;
                }
            }
            res = (res==INT_MIN) ? count : res;
            memo[i][j][isTrue] = res%1003;
        }
        return memo[i][j][isTrue]%1003;
    }
    int countWays(int N, string S){
        memset(memo,-1,sizeof(memo));
        return func(S,0,S.size()-1,true);
    }
};