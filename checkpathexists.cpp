class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool dfs(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&vis)
    {
        if(grid[i][j]==2)
        {
            return true;
        }
        vis[i][j]=1;
        if(i-1>=0 && !vis[i-1][j] && grid[i-1][j]!=0)
        {
            if(dfs(i-1,j,n,m,grid,vis))
            {
                return true;
            }
        }
        if(j-1>=0 && !vis[i][j-1] && grid[i][j-1]!=0)
        {
            if(dfs(i,j-1,n,m,grid,vis))
            {
                return true;
            }
        }
        if(i+1<n && !vis[i+1][j] && grid[i+1][j]!=0)
        {
            if(dfs(i+1,j,n,m,grid,vis))
            {
                return true;
            }
        }
        if(j+1<m && !vis[i][j+1] && grid[i][j+1]!=0)
        {
            if(dfs(i,j+1,n,m,grid,vis))
            {
                return true;
            }
        }
        return false;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    if(dfs(i,j,n,m,grid,vis))
                    {
                        return true;
                    }
                    return false;
                }
            }
        }
        return false;
    }
};
