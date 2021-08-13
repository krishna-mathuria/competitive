#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int low, int high)
{
    while (low < high)
    {
        if (str[low] != str[high])
            return false;
        low++;
        high--;
    }
    return true;
}

void allPalUtil(string s, vector<string> &curr,vector<vector<string>> &ans,int index){
    if(index==s.length()){
        ans.push_back(curr);
        return;
    }
    for(int i=index;i<s.size();i++){
        if(isPalindrome(s,index,i)){
            curr.push_back(s.substr(index,i-index+1));
            allPalUtil(s,curr,ans,i+1);
            curr.pop_back();
        }
    }   
}


void allPalPartitions(string s){
    vector<vector<string>> ans;
    vector<string> curr;
    
    allPalUtil(s,curr,ans,0);
    
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
    }
}

int main()
{
    string str = "nitin";
    allPalPartitions(str);
    return 0;
}