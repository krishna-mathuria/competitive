class Solution
{
public:
    void traverse(Node *root,int sum,int &maxsum,int h, int &maxh){
        if(!root) return;
        sum+=root->data;
        if(!root->left && !root->right && h>=maxh)
        {
            maxh=h;
            maxsum = max(maxsum,sum);
        }
        traverse(root->left,sum,maxsum,h+1,maxh);
        traverse(root->right,sum,maxsum,h+1,maxh);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int maxsum = 0,maxh=0;
        traverse(root,0,maxsum,0,maxh);
        return maxsum;
    }
};