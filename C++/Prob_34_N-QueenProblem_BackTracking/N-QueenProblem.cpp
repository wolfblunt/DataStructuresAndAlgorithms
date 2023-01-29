#include<bits/stdc++.h>
using namespace std;

// bool isSafe(vector<vector<int>>&board, int row, int col)
// {
// 	int i,j;
// 	int n = board.size();
// 	for(i=row-1,j=col;i>=0;i--)
// 	{
// 		if(board[i][j])
// 		{
// 			return false;
// 		}
// 	}

// 	for(i=row-1,j=col-1;i>=0,j>=0;i--,j--)
// 	{
// 		if(board[i][j])
// 		{
// 			return false;
// 		}
// 	}

// 	for(i=row-1,j=col+1;i>=0,j<n;j++,i--)
// 	{
// 		if(board[i][j])
// 		{
// 			return false;
// 		}
// 	}

// 	return true;
// }

// void nQueen(vector<vector<int>>&board, vector<vector<int>>&answer, vector<int>&position, int n, int row)
// {
// 	if(row==n)
// 	{
// 		answer.push_back(position);
// 		return;
// 	}
// 	for(int col=0;col<n;col++)
// 	{
// 		if(isSafe(board,row,col))
// 		{
// 			board[row][col]=1;
// 			position.push_back(col+1);
// 			nQueen(board, answer, position, n, row+1);
// 			board[row][col]=0;
// 			position.pop_back();
// 		}
// 	}
// } 

// vector<vector<int>> nQueenBoard(int n)
// {
// 	vector<vector<int>> answer;
// 	vector<int> position;
// 	vector<vector<int>> board(n,vector<int>(n,0));
// 	nQueen(board, answer, position, n, 0);
// 	return answer;
// }


bool issafe(vector<vector<int>>&board,int row,int col){
	cout<<"row: "<<row<<" col: "<<col<<"\n";
   for(int i=row-1,j=col;i>=0;i--){
       if(board[i][j]==1){
           return false;
       }
   }
   cout<<"#################";
   for(int i=row-1,j=col-1;i>=0 and j>=0;i--,j--){
       if(board[i][j]==1){
           return false;
       }
   }
   for(int i=row-1,j=col+1;i>=0 and j<board.size();i--,j++){
       if(board[i][j]==1){
           return false;
       }
   }
   return true;
}
void solve(int row,vector<vector<int>>&ans,vector<vector<int>>&board,vector<int>&ds,int n){
   if(row==n){
       ans.push_back(ds);
       return;
   }
   for(int col=0;col<n;col++){
       if(issafe(board,row,col)){
           board[row][col]=1;
           ds.push_back(col+1);
           solve(row+1,ans,board,ds,n);
           board[row][col]=0;
           ds.pop_back();
       }
   }
}
   vector<vector<int>> nQueen(int n) {
       // code here
       vector<vector<int>>ans;
       vector<int>ds;
       vector<vector<int>>board(n,vector<int>(n,0));
       solve(0,ans,board,ds,n);
       return ans;
   }

int main()
{
	int n;
	cin>>n;
	vector<vector<int>> ans = nQueen(n);
    if(ans.size() == 0)
        cout<<-1<<"\n";
    else {
        for(int i = 0;i < ans.size();i++){
            cout<<"[";
            for(int u: ans[i])
                cout<<u<<" ";
            cout<<"] ";
        }
        cout<<endl;
    }
}

