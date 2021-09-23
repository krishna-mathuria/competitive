class Solution {
public:
    bool isRobotBounded(string s) {
        int move1=0;
        int move2=0;
        int dir = 1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L') {
                if(dir==1){
                    dir=4;
                }
                else
                    dir--;
            }
            else if(s[i]=='R') {
                if(dir==4){
                    dir=1;
                }
                else
                    dir++;
            }     
            else{
                if(dir==1) move1++;
                else if(dir==2) move2++;
                else if(dir==3) move1--;
                else  move2--;
            }
        }
        if(dir!=1) return 1;
        else if(move1==0 && move2==0){
            return 1;
        }
        return 0;
    }
};