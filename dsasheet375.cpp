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

bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
  
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;
  
        pCrawl = pCrawl->children[index];
    }
  
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}
  bool wordBreak(string str, TrieNode *root)
{
    int size = str.size();
  
    // Base case
    if (size == 0)  return true;
  
    // Try all prefixes of lengths from 1 to size
    for (int i=1; i<=size; i++)
    {

        if (search(root, str.substr(0, i)) &&
            wordBreak(str.substr(i, size-i), root))
            return true;
    }

    return false;
}

// Driver
int main()
{
    string dictionary[] = {"mobile","samsung","sam",
                           "sung","ma\n","mango",
                           "icecream","and","go","i",
                           "like","ice","cream"};
    int n = sizeof(dictionary)/sizeof(dictionary[0]);
    struct TrieNode *root = getNode();
  
    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, dictionary[i]);
  
    wordBreak("ilikesamsung", root)? cout <<"Yes\n": cout << "No\n";
    wordBreak("iiiiiiii", root)? cout <<"Yes\n": cout << "No\n";
    wordBreak("", root)? cout <<"Yes\n": cout << "No\n";
    wordBreak("ilikelikeimangoiii", root)? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmango", root)? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmangok", root)? cout <<"Yes\n": cout << "No\n";
    return 0;
}
