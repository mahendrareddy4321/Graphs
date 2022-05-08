class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&grid1,vector<vector<int>>&grid2,int n,int m,bool &isgood)
    {
        if(i<0 ||j<0 ||i>=n || j>=m || grid2[i][j]==0)
        {
            return;
        }
        if(grid1[i][j]!=grid2[i][j])
        {
            isgood=false;
        }
        grid2[i][j]=0;
        dfs(i-1,j,grid1,grid2,n,m,isgood);
        dfs(i,j-1,grid1,grid2,n,m,isgood);
        dfs(i,j+1,grid1,grid2,n,m,isgood);
        dfs(i+1,j,grid1,grid2,n,m,isgood);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j]==1)
                {
                    bool isgood=true;
                    dfs(i,j,grid1,grid2,n,m,isgood);
                    if(isgood==true)
                    {
                        c++;
                    }
                }
            }
        }
        return c;
    }
};
