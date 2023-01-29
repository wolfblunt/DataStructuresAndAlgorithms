#include<iostream>
using namespace std;

class Node {
public:
	string word;
	Node* next;

	Node(string word)
	{
		this->word = word;
		this->next = NULL;
	}
};

class LinkedList {
	Node* head;
public:
	LinkedList() { 
		head = NULL; 
	}
	void storingString(string data)
	{
		Node* newNode = new Node(data);
		if(head==NULL)
		{
			head = newNode;
			return;
		}

		Node *temp = head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}

		temp->next = newNode;
	}

	void printLinkedList()
	{
		Node* temp = head;
		if(head==NULL)
		{
			cout<<""<<endl;
			return;
		}
		while(temp!=NULL)
		{
			cout<<temp->word;
			temp = temp->next;
			cout<<"\n";
		}
	}
};

class TrieNode{
public:
	string word;
	TrieNode* children[26];
	bool isTerminal;

	TrieNode()
	{
		// word=ch;
		isTerminal = false;
		for(int i=0;i<26;i++)
		{
			children[i] = NULL;
		}
	}
};

class Trie {
public:
	TrieNode* root;
	LinkedList ll;

	void insertWord(TrieNode* root, string searchWord)
	{
		TrieNode* temp = root;
		for(int i=0;i<searchWord.length();i++)
        {
            int index = searchWord[i] - 'a';
            if(temp->children[index] == NULL)
                temp->children[index] = new TrieNode();
            
            temp = temp->children[index];
        }
        temp->word = searchWord;
        temp->isTerminal = true;
	}

	// void matchPattern(char grid[][10], vector<string> &ans, int row, int col, int i, int j, TrieNode* root)
	void matchPattern(char grid[][10], int row, int col, int i, int j, TrieNode* root)
	{
		if(i<0 || j<0 || i>(row-1) || j>(col-1) || grid[i][j]=='-' || !(root->children[grid[i][j]-'a']))
	    {
	        return;
	    }

	    root = root->children[grid[i][j]-'a'];

	    if(root->isTerminal)
	    {
	    	// ans.push_back(root->word);
	    	ll.storingString(root->word);
	    	root->isTerminal = false;
	    }

	    char temp = grid[i][j];
        grid[i][j] = '-';
        // cout<<"\n##########Grid################\n";
        // for(int a=0;a<row;a++)
        // {
        //     for(int b=0;b<col;b++)
        //     {
        //         cout<<grid[a][b];
        //     }
        //     cout<<"\n";
        // }
        matchPattern(grid, row, col, i-1, j, root);
        matchPattern(grid, row, col, i+1, j, root);
        matchPattern(grid, row, col, i, j-1, root);
        matchPattern(grid, row, col, i, j+1, root);
        grid[i][j] = temp;
        return;
	}

	void puzzleSolver(int row, int col,TrieNode* root,char grid[][10])
	{
		TrieNode* temp = root;
		// vector<string> ans;

	    for(int i=0;i<row;i++)
	    {
	        for(int j=0;j<col;j++)
	        {
                // matchPattern(grid, ans, row, col, i, j, temp);
        		matchPattern(grid, row, col, i, j, temp);
	        }
	    }
	    cout<<"\n";

	    ll.printLinkedList();
	}
};

int main()
{
	Trie t;
	TrieNode* root = new TrieNode();
	int row,col;
    cin>>row;
    cin>>col;
    char grid[row][10];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            char c;
            cin>>c;
            grid[i][j]=c;
        }
    }
    int noOfTestString;
    cin>>noOfTestString;
    for(int i=0;i<noOfTestString;i++)
    {
        string pattern;
        cin>>pattern;
        t.insertWord(root, pattern);
    }
    t.puzzleSolver(row, col, root, grid);
	return 0;

	// Input 
	// 4 4
    // oaan
    // etae
    // ihkr
    // iflv
    // 6
    // oath
    // pea
    // eat
    // rain
    // hklf
    // hf
}