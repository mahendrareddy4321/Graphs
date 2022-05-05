class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>>q;
        int c=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                if(grid[i][j]==1)
                {
                    c++;
                }
            }
        }
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty())
        {
            int s=q.size();
            int flag=0;
            for(int i=0;i<s;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x-1>=0 && grid[x-1][y]==1)
                {
                    flag=1;
                    grid[x-1][y]=2;
                    q.push({x-1,y});
                    c--;
                }
                if(x+1<n && grid[x+1][y]==1)
                {
                    flag=1;
                    grid[x+1][y]=2;
                    q.push({x+1,y});
                    c--;
                }
                if(y-1>=0 && grid[x][y-1]==1)
                {
                    flag=1;
                    grid[x][y-1]=2;
                    q.push({x,y-1});
                    c--;
                }
                if(y+1<m && grid[x][y+1]==1)
                {
                    flag=1;
                    grid[x][y+1]=2;
                    q.push({x,y+1});
                    c--;
                }
            }
            if(flag==1)
            {
                ans++;
            }
        }
        if(c!=0)
        {
            return -1;
        }
        return ans;
    }
};
