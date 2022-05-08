class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&grid,int n,int m)
    {
        if(i<0 || j<0 || i>=n || j>=m ||grid[i][j]==0)
        {
            return;
        }
        grid[i][j]=0;
        dfs(i-1,j,grid,n,m);
        dfs(i,j-1,grid,n,m);
        dfs(i+1,j,grid,n,m);
        dfs(i,j+1,grid,n,m);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            dfs(i,0,grid,n,m);
            dfs(i,m-1,grid,n,m);
        }
        for(int i=0;i<m;i++)
        {
            dfs(0,i,grid,n,m);
            dfs(n-1,i,grid,n,m);
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    c++;
                }
            }
        }
        return c;
    }
};
