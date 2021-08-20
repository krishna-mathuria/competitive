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
            if(wb[i]==false && dictionaryContains(str.substr(0,i),B))
                wb[i]= true;
                
            if(wb[i]==true){
                if(i==size)
                    return true;
                
                for(int j=i+1;j<=size;j++){
                    if(wb[j]==false && dictionaryContains(str.substr(i,j-i),B))
                        wb[j] = true;
                if (j == size && wb[j] == true)
                    return true;
                }
            }
        }
        return false;
    }
};