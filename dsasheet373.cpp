// C++ implementation of search and insert
// operations on Trie
#include <bits/stdc++.h>
using namespace std;

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

void search(struct TrieNode *root, string key,vector<string>& v)
{
	struct TrieNode *pCrawl = root;
    string s="";
    int count=0;
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		for(int j=0;j<26;j++){
		    if(pCrawl->children[j]!=NULL) count++;

		}
		if(count>1){
	        count=0;
	    }
	    if(count==1){
	        v.push_back(s);
	        return;
	    }
        s+=key[i];
		pCrawl = pCrawl->children[index];
		
	}
    if(pCrawl->isEndOfWord==true){
        v.push_back(s);
        return;
    }
	return;
}

// Driver
int main()
{

	string keys[] = {"zebra", "dog", "duck", "dove"};
	
	int n = 4;
    vector<string> v;
	struct TrieNode *root = getNode();

	// Construct trie
	for (int i = 0; i < n; i++)
		insert(root, keys[i]);

    for(int i =0;i<n;i++){
        search(root,keys[i],v);
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
	return 0;
}
