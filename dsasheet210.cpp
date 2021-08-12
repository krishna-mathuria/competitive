class Solution
{
public:
    void inorder(Node *root,unordered_map<int,int> &mp,int x){
        if(root!=NULL){
            inorder(root->left,mp,x);
            mp[x-root->data]++;
            inorder(root->right,mp,x);
        }
    }
    void inorder2(Node *root,unordered_map<int,int> &mp,int &count){
        if(root!=NULL){
            inorder2(root->left,mp,count);
            if(mp[root->data]==1) count++;
            inorder2(root->right,mp,count);
        }
    }
    int countPairs(Node* root1, Node* root2, int x)
    {
        unordered_map<int,int> mp;
        inorder(root1,mp,x);
        int count = 0;
        inorder2(root2,mp,count);
        return count;
    }
};