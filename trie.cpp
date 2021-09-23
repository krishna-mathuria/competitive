void insert(struct TrieNode *root, string key)
{
    TrieNode* head = root;

    for(int j=0;j<key.length();j++)
    {
        int index = key[j]-'a';
        if(head->children[index]==NULL)
        {
            head->children[index] = getNode();
        }
        head = head->children[index];
    }
    head->isLeaf = 1;
}
bool search(struct TrieNode *root, string key) 
{
    TrieNode*head=root;
    for(int i=0;i<key.length();i++)
    {
        int index = key[i]-'a';
        if(head->children[index]==NULL)
        return 0;
        head = head->children[index];
    }
    return (head->isLeaf);
}