class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int m = heights.size();
        long long area=INT_MIN;
        stack<long long> s;
        s.push(-1);
        vector<long long> left_smaller(m, -1), right_smaller(m, m);
        long long i=0;
        while(i<m){
            while(!s.empty()&&s.top()!=-1&&heights[s.top()]>heights[i]){
                right_smaller[s.top()] = i;
                s.pop();
            }
            if(i>0&&heights[i]==heights[i-1]){
               left_smaller[i] = left_smaller[i-1];
            }else{

                left_smaller[i] = s.top();
            } 
            s.push(i);
            i++;
        }
        

        for(long long j = 0; j<m; j++){
            area = max(area, heights[j]*(right_smaller[j]-left_smaller[j]-1));
        }
        return area;
    }
};