// Word Search : O(N∗M∗4^L)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void matchPattern(vector<vector<char>>& board, string &word, int n, int m, int r, int c, int index, bool &matchFlag)
    {
        if(r<0 || r>=n || c<0 || c>=m || word[index] != board[r][c] || board[r][c] == '-' || index>word.length())
        {
            return;
        }
        

        if(index==word.length()-1)
        {
            matchFlag = true;
            return;
        }
        
        char temp = board[r][c];
        board[r][c] = '-';
        vector<vector<int>> v = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(auto a: v)
        {
            matchPattern(board, word, n, m, r+a[0], c+a[1], index+1, matchFlag);
        }
        board[r][c] = temp;
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int index = 0;
        bool matchFlag = false;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!matchFlag){
                    matchPattern(board, word, n, m, i, j, index, matchFlag);
                }
                else
                    break;
            }
            if(matchFlag)
                break;
        }
        
        if(!matchFlag)
            return 0;
        return 1;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}