// Predict the Winner

class Solution {
public:
    int solve(vector<vector<int>>&dp,vector<int>&v,int i,int j,int k){
        if(i>j)
    	{	
    		return 0;
    	}

        if(dp[i][j]!=-1)
        {	
        	return dp[i][j];
        }

        int first=0,last=0,ans=0;
        if(k%2==0){// it's player 1's turn
            first=v[i]+solve(dp,v,i+1,j,k+1); // pick the first element and add it to the score of player 1
            last=v[j]+solve(dp,v,i,j-1,k+1); // pick the last element and add it to the score player 1
            ans=max(first,last);//store the ans which will return the max score for player 1 
        }
        else{// it's player 2's turn
            first=-v[i]+solve(dp,v,i+1,j,k+1); // pick the first element and subtract it from the score of player 1
            last=-v[j]+solve(dp,v,i,j-1,k+1); // pick the lastelement and subtract it from the score of player 1
            ans=min(first,last);//store the ans which will return the min score for player 1 
        }
        
        return dp[i][j]=ans;
    }

    bool PredictTheWinner(vector<int>&v) {
        int i,n=v.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(dp,v,0,n-1,0)>=0; // ans >=0 implies player 1's score is greater than player 2's score
    }
};