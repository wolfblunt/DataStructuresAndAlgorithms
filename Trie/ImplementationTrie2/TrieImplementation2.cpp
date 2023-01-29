#include<iostream>
using namespace std;

class TrieNode{
public:
	TrieNode* children[26];
	int countEndWith = 0;
	int countPrefix = 0;

	bool containsKey(char ch)
	{
		return (children[ch-'a']!=NULL);
	}

	TrieNode* get(char ch)
	{
		return children[ch - 'a'];
	}

	void put(char ch, TrieNode* node)
	{
		children[ch - 'a'] = node;
	}

	void increasePrefix()
	{
		countPrefix++;
	}

	void increaseEnd()
	{
		countEndWith++;
	}

	void deleteEnd()
	{
		countEndWith--;
	}

	void reducePrefix()
	{
		countPrefix--;
	}

	int getEnd()
	{
		return countEndWith;
	}

	int getPrefix()
	{
		return countPrefix;
	}
};

class Trie {
private:
	TrieNode* root;

public:
	Trie()
	{
		root = new TrieNode();
	}

	void insert(string word)
	{
		TrieNode* node = root;
		for(int i=0;i<word.length();i++)
		{
			if(!node->containsKey(word[i]))
			{
				node->put(word[i], new TrieNode());
			}
			node = node->get(word[i]);
			node->increasePrefix();
		}

		node->increaseEnd();
	}

	int countWordsEqualTo(string& word)
	{
		TrieNode* node = root;
		for(int i=0;i<word.length();i++)
		{
			if(node->containsKey(word[i]))
			{
				node = node->get(word[i]);
			}
			else{
				return 0;
			}
		}

		return node->getEnd();
	}

	int countWordsStartingWith(string& word)
	{
		TrieNode* node = root;
		for(int i=0;i<word.length();i++)
		{
			if(node->containsKey(word[i]))
			{
				node = node->get(word[i]);
			}
			else{
				return 0;
			}
		}
		return node->getPrefix();
	}

	void erase(string& word)
	{
		TrieNode* node = root;
		for(int i=0;i<word.length();i++)
		{
			if(node->containsKey(word[i]))
			{
				node = node->get(word[i]);
				node->reducePrefix();
			}
			else{
				return;
			}
		}
		node->deleteEnd();
	}
};

int main()
{
	Trie t;
	t.insert("apple");
	t.insert("apple");
	t.insert("apps");
	t.insert("apps");

	string word1 = "apps";
	cout<<"Count Words Equal to "<< word1<<" "<<t.countWordsEqualTo(word1)<<endl;
  	string word2 = "abc";
  	cout<<"Count Words Equal to "<< word2<<" "<<t.countWordsEqualTo(word2)<<endl;
  	string word3 = "ap";
  	cout<<"Count Words Starting With "<<word3<<" "<<t.countWordsStartingWith(word3)<<endl;
  	string word4 = "appl";
  	cout<<"Count Words Starting With "<< word4<<" "<<t.countWordsStartingWith(word4)<<endl;
  	t.erase(word1);
  	cout<<"Count Words equal to "<< word1<<" "<<t.countWordsEqualTo(word1)<<endl;
	return 0;
}