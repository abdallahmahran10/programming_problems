#include "../common.h"

#define ALPHABET_SIZE 26
#define INDEX(c) (int)((c) - 'a')

struct TrieNode
{
	TrieNode *nodes[ALPHABET_SIZE];
	bool isLeaf;

	TrieNode()
	{
		isLeaf= false;
		for(int i=0; i<ALPHABET_SIZE; i++)
			nodes[i] = NULL;
	}
};

class DialingSystem
{
private:
	map<int, string> keys;
	TrieNode *root;

public:
	DialingSystem(vector<string> db)
	{
		fillKeys();
		root = getNode();
		for(int i=0; i<db.size(); i++)
			insertWord(db[i]);
	}
	
	void fillKeys()
	{
		keys[1] = "";
		keys[2] ="abc";
		keys[3] ="def"; // and so on
	}

	void insertWord(string word)
	{
		TrieNode *slider=root;
		for(int level=0; level<word.length(); level++)
		{
			if(!slider->nodes[INDEX(word[level])])
				slider->nodes[INDEX(word[level])] = getNode();
			slider = slider->nodes[INDEX(word[level])];
		}
		//
		slider->isLeaf = true;
	}

	char getChar(int key, int charIdx)
	{
		return keys[key][charIdx];
	}

	void searchByNumbersRec(string partial, string constructed, int keyIdx, int charIdx, vector<string> &results)
	{
		if(keyIdx == partial.size())
		{
			searchByWord(constructed, results);
		}
		else
		{
			constructed[keyIdx] = getChar(keyIdx, charIdx);
			for(int i=0; keys[partial[keyIdx]].size();i++)
				searchByNumbersRec(partial, constructed,keyIdx,  i, results);
			searchByNumbersRec(partial, constructed,keyIdx +1,  0, results);
		}
	}

	vector<string> searchByNumbers(string partial /*227*/)
	{
		vector<string> results;
		string constructed(partial.size(), ' ');
		searchByNumbersRec(partial,constructed, 0, 0, results);
		return results;
	}

	void searchByWord(string partial, vector<string> &results)
	{
		TrieNode *slider=root;
		string str;
		for(int level=0; level<partial.length(); level++)
		{
			if(!slider->nodes[INDEX(partial[level])])
				return;
			slider = slider->nodes[INDEX(partial[level])];
		}


	}

	TrieNode *getNode()
	{
		return new TrieNode();
	}

};