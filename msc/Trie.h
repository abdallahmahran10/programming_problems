/*
	Author: Abdallah Mahran
	file: Trie.h
	description: Implmentation of the Trie data structure
*/
/********************** MACROS ******************/
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
/******************** INCLUDES *****************/
/******************** TrieNode *****************/
struct TrieNode{
    TrieNode *children[ALPHABET_SIZE];
	TrieNode(){}
    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

/******************** Trie *****************/
class Trie
{
private:
	TrieNode *mRoot;
	TrieNode *createNode()
	{
		TrieNode *pNode = new TrieNode();
		pNode->isLeaf = false;
		//
        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
		return pNode;
	}
	//
	void insert(const string &str, size_t i, TrieNode *node)
	{
		if(i == str.size())
			node->isLeaf = true;
		if(i>str.size())
			return;
		if(node == NULL)
			return;
		if(node->children[CHAR_TO_INDEX(str[i])] == NULL)
			node->children[CHAR_TO_INDEX(str[i])] = createNode();
		insert(str, i+1, node->children[CHAR_TO_INDEX(str[i])]);

	}
	//
	bool search(const string &str, size_t i, TrieNode *node)
	{
		if(i == str.size())
		{
			return node->isLeaf;
		}
		if(i>str.size())
			return false;
		if(node == NULL)
			return false;
		if(node->children[CHAR_TO_INDEX(str[i])] == NULL)
			return false;
		else 
			search(str, i+1, node->children[CHAR_TO_INDEX(str[i])]);
	}
public:	
	Trie()
	{
		mRoot = createNode();
	}
	//
	void insert(const string &str)
	{
		if(str.empty())
			return;
		insert(str, 0, mRoot);
	}
	//
	void insert(const char *cStr)
	{
		insert(string(cStr));
	}
	//
	bool search(const string &str)
	{
		search(str, 0, mRoot);
	}
	// Returns true if key presents in trie, else false
	bool search(const char *key)
	{
		return search(string(key));
	}
};