
class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    string preorder(Node *root,unordered_map<string,int> &mp){
        string s;
        if(root==NULL) {
            s+='$';
            return s;
        }
        s+=root->data;
        s+=preorder(root->left,mp);
        s+=preorder(root->right,mp);
        mp[s]++;
        return s;
    }
    int dupSub(Node *root) {
         // code here
         unordered_map<string,int> mp;
         preorder(root,mp);
         for(auto i:mp)
            if(i.second>=2 && i.first.length()>3)
                 return 1;
         return 0;
         
    }
};