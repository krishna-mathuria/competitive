class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
        char sign = '+';
        long long res = 0;
        long long tmp = 0;
        for (unsigned int i = 0; i < s.size(); i++) {
            if (isdigit(s[i]))
                tmp = 10*tmp + s[i]-'0';
            if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size()-1) {
                if (sign == '-')
                    st.push(-tmp);
                else if (sign == '+')
                    st.push(tmp);
                else {
                    long long num;
                    if (sign == '*' )
                        num = st.top()*tmp;
                    else
                        num = st.top()/tmp;
                    st.pop();
                    st.push(num);
                } 
                sign = s[i];
                tmp = 0;
            }
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};