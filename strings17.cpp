#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int dictionaryContains(string word, vector<string> &dictionary)
    {

        int size = dictionary.size();
        for (int i = 0; i < size; i++){
            if (dictionary[i].compare(word) == 0)
               return true;
        }
        return false;
    }
    int wordBreak(string str, vector<string> &B) {
       

    int size = str.length();
    bool wb[size+1];
    memset(wb, 0, sizeof(wb)); 
 
    for (int i=1; i<=size; i++)
    {

        if (wb[i] == false && dictionaryContains( str.substr(0, i),B ))
            wb[i] = true;
 

        if (wb[i] == true)
        {
            // If we reached the last prefix
            if (i == size)
                return true;
 
            for (int j = i+1; j <= size; j++)
            {
                // Update wb[j] if it is false and can be updated
                // Note the parameter passed to dictionaryContains() is
                // substring starting from index 'i' and length 'j-i'
                if (wb[j] == false && dictionaryContains( str.substr(i, j-i),B ))
                    wb[j] = true;

                if (j == size && wb[j] == true)
                    return true;
            }
        }
    }
    return false;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}