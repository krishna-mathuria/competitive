
class node{
    public:
        node* left;
        node* right;
        int freq;
        node(int data){
            freq=data;
            left=right=nullptr;
        }
};


class cmp {
    public:
        bool operator()(node *l1,node *l2){
            return l1->freq > l2->freq;
        }
    };
    
class Solution{
    public:
        void traversal(vector<string> &ans,node *root,string s){
            if(!root) return;
            if(!root->left and !root->right){
                ans.push_back(s);
            }
            traversal(ans,root->left,s+"0");
            traversal(ans,root->right,s+"1");
        }
    
        vector<string> huffmanCodes(string S,vector<int> f,int N)
        {
            priority_queue<node*,vector<node*>,cmp> pq;
            for(int i=0;i<f.size();i++){ 
                node* temp= new node(f[i]); 
                pq.push(temp); 
            } 
            while(pq.size()!=1){ 
                node* t=pq.top();
                pq.pop();
                node* q=pq.top();
                pq.pop(); 
                node* temp=new node(t->freq+q->freq);
                temp->left=t;
                temp->right=q;
                pq.push(temp);
            }
            vector<string> ans;
            traversal(ans,pq.top(),"");
            return ans;
        }
};