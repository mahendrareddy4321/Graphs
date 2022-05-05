class Solution {
  public:
    // Function to find the number of islands.
    int island(int i,int j,vector<vector<char>>& grid)
    {
        if(i<0 || j<0 || i>=grid.size()|| j>=grid[i].size())
        {
            return 0;
        }
        if(grid[i][j]=='1')
        {
            grid[i][j]='0';
            int x=island(i+1,j,grid);
            int y=island(i,j+1,grid);
            int w=island(i-1,j,grid);
            int v=island(i,j-1,grid);
            int z=island(i-1,j-1,grid);
            int u=island(i+1,j+1,grid);
            int t=island(i+1,j-1,grid);
            int s=island(i-1,j+1,grid);
            if(1+s+t+u+v+w+x+y+z>=1)
            {
                return 1;
            }
        }
        return 0;
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    count+=island(i,j,grid);
                }
            }
        }
        return count;
    }
};
