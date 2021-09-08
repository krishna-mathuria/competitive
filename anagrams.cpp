#include<bits/stdc++.h>
using namespace std;

void solver(vector<string> mylist){
    
    map<map<char,int>,vector<string>> mp;
    
    for(auto s : mylist){
        map<char,int> temp;
        vector<string> tempvec;
        for(auto x: s){
            temp[x]++;
        }
        auto itr = mp.find(temp);
        if(itr!=mp.end()){
            itr->second.push_back(s);
        }
        else{
            tempvec.push_back(s);
            mp.insert({temp,tempvec});
        }
    }
    
    vector<vector<string>> result;
 
    for(auto it = mp.begin();
             it != mp.end(); ++it)
    {
        result.push_back(it->second);
    }
 
    for(int i = 0; i < result.size(); ++i)
    {
          cout << "[";
        for(int j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j] << ", ";
        }
          cout << "]";
    }
}

int main()
{
    vector<string> my_list = { "cat", "dog", "ogd",
                               "god", "atc" };
    solver(my_list);
    return 0;
}