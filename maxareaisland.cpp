class Solution {
public:
    int DFS(vector<vector<int>>& grid,vector<vector<bool>>& vis,int i,int j,int n,int m)
    {
        
        if(i<0||i>=n||j<0||j>=m){
            return 0;
        }
        if(grid[i][j]==0 || vis[i][j]==true)
        {
            return 0;
        }
        vis[i][j]=true;
        return 1+DFS(grid,vis,i+1,j,n,m)+
            DFS(grid,vis,i-1,j,n,m)+DFS(grid,vis,i,j+1,n,m)+DFS(grid,vis,i,j-1,n,m);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

 		int n = grid.size();
 		int m = grid[0].size();
 		vector<vector<bool>>vis(n, vector<bool>(m, false));
        int maxi=0;
         for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 if(grid[i][j]==1 and !vis[i][j])
                 {
                     maxi=max(maxi,DFS(grid,vis,i,j,n,m));
                 }
            }
        }
        
        return maxi;
    }
};
