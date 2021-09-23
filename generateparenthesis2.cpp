class Solution
{
    public:
    void solve(int n,int o,int c,string s,vector<string>& str)
    {
        if(o==0 && c==0)
        {
            str.push_back(s);
            return ;
        }
        if(o!=0)
        {
            string s1 = s;
            s1 = s1+'(';
            solve(n,o-1,c,s1,str);
        }
        if(o<c)
        {
            string s2 = s;
            s2 = s2+')';
            solve(n,o,c-1,s2,str);
        }
    }
    
    vector<string> AllParenthesis(int n) 
    {
        string s="";
        vector<string> str;
        int open = n;
        int close = n;
        solve(n,open,close,s,str);
        return str;
    }
};