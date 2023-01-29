#include<iostream>
using namespace std;

class TrieNode {
public:
	char data;
	TrieNode* children[26];
	bool isTerminal;

	TrieNode(char ch)
	{
		data = ch;
		for(int i=0;i<26;i++)
		{
			children[i] = NULL;
		}
		isTerminal = false;
	}
};


class Trie{
	public:
	TrieNode* root;

	Trie()
	{
		root = new TrieNode('\0');
	}

	void insertUtility(TrieNode* root, string word)
	{
		// BASE CASE
		if(word.length()==0)
		{
			root->isTerminal = true;
			return;
		}

		int index = word[0] - 'a';
		TrieNode* child;

		if(root->children[index]!=NULL)
		{
			child = root->children[index];
		}
		else
		{
			child = new TrieNode(word[0]);
			root->children[index] = child;
		}

		insertUtility(child, word.substr(1));
	}

	bool searchUtility(TrieNode* root, string word)
	{
		// base case
		if(word.length()==0)
		{
			return root->isTerminal;
		}

		int index = word[0] - 'a';
		TrieNode* child;

		if(root->children[index] != NULL)
		{
			child = root->children[index];
		}
		else
		{
			return false;
		}

		return searchUtility(child, word.substr(1));
	}

	void deleteUtility(TrieNode* root, string word)
	{
		if(word.length() == 0)
		{
			root->isTerminal = false;
		}

		TrieNode* child;
		int index = word[0] - 'a';

		if(root->children[index]!=NULL)
		{
			child = root->children[index];
		}

		else
		{
			return;
		}
		deleteUtility(child, word.substr(1));
		return;
	}

	bool startsWithUtility(TrieNode* root, string prefix)
	{
		if(prefix.length()==0)
		{
			return true;
		}

		int index = prefix[0] - 'a';
		TrieNode* child;

		if(root->children[index]!=NULL)
		{
			child = root->children[index];
		}
		else
		{
			return false;
		}
		return startsWithUtility(child, prefix.substr(1));
	}

	void insertWord(string word)
	{
		insertUtility(root, word);
	}

	bool searchWord(string word)
	{
		bool result = searchUtility(root, word);
		return result;
	}

	void deleteWord(string word)
	{
		deleteUtility(root, word);
	}

	bool startsWith(string prefix) {
		return startsWithUtility(root, prefix);
    }
};


int main()
{
	Trie *t = new Trie();

	t->insertWord("aman");
	t->insertWord("apar");
	t->insertWord("aryan");
	t->insertWord("akhil");
	cout<<t->searchWord("apar")<<"\n";
	t->deleteWord("apa");
	cout<<t->searchWord("apar");
	cout<<"\n"<<t->startsWith("am");
	return 0;
}