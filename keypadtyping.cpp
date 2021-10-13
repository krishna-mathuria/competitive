string printNumber(string s, int n)
{
string r="";
int i;
    for(i=0;i<n;i++) {
        if(s[i]>='a'&&s[i]<='c')
            r=r+'2';
        else if(s[i]>='d'&&s[i]<='f')
            r=r+'3';
        else if(s[i]>='g'&&s[i]<='i')
            r=r+'4';
        else if(s[i]>='j'&&s[i]<='l')
            r=r+'5';
        else if(s[i]>='m'&&s[i]<='o')
            r=r+'6';
        else if(s[i]>='p'&&s[i]<='s')
            r=r+'7';
        else if(s[i]>='t'&&s[i]<='v')
            r=r+ '8';
        else if(s[i]>='w'&&s[i]<='z')
            r=r+ '9';
    }
    return r;
}
