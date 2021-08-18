const int ALPHABET_SIZE = 26;

struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];

	bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
	struct TrieNode *pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}


void insert(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}

	pCrawl->isEndOfWord = true;
}
bool isLeafNode(struct TrieNode* root)
{
    return root->isEndOfWord != false;
}
void display(struct TrieNode* root, string str, int level,vector<string>& res)
{

    if (isLeafNode(root)) 
    {
        res.push_back(str);
        return;
    }
  
    int i;
    for (i = 0; i < 26; i++) 
    {

        if (root->children[i]) 
        {
            str += i + 'a';
            display(root->children[i], str, level + 1,res);
        }
    }
}
void search(struct TrieNode *root, string key,vector<vector<string>>& ans){
    vector<string> res;
    vector<string> nul;
    nul.push_back("0");
    struct TrieNode *pCrawl = root;
  
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]){
            ans.push_back(nul);
            return;
        }
  
        pCrawl = pCrawl->children[index];
    }
    
    display(pCrawl,key,key.length(),res);
    ans.push_back(res);
    return;
}

class Solution{
public:

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>> ans;
        struct TrieNode *root = getNode();
  
        for (int i = 0; i < n; i++)
            insert(root, contact[i]);
            
            
        for(int i=1;i<s.size()+1;i++){
            search(root,s.substr(0,i),ans);
        }
        return ans;
    }
};