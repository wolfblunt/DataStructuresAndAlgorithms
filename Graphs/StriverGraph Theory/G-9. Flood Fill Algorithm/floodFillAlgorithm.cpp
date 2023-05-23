// Flood fill Algorithm

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& newImage, int initialColor, int sr, int sc, int newColor, vector<vector<int>>& dirs, vector<vector<bool>>& visited)
    {
        if(sr<0 || sr>=newImage.size() || sc<0 || sc>=newImage[0].size() || newImage[sr][sc]!=initialColor || visited[sr][sc])
        {
            return;
        }

        newImage[sr][sc] = newColor;
        visited[sr][sc] = true;
        for(auto a: dirs)
        {
            dfs(newImage, initialColor, sr+a[0], sc+a[1], newColor, dirs, visited);
        }
    }    

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        vector<vector<int>> newImage = image;
        int initialColor = newImage[sr][sc];
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        dfs(newImage, initialColor, sr,sc, newColor, dirs, visited);
        return newImage;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}