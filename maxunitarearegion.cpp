class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    void dfs(int i,int j,int n,int m,vector<vector<int>>& arr,vector<vector<int>>&vis,int &cnt)
    {
        if(i<0 || j<0 ||i>=n ||j>=m)
        {
            return;
        }
        vis[i][j]=1;
        if(j-1>=0 && !vis[i][j-1] && arr[i][j-1]!=0)
        {
              cnt+=1;
              dfs(i,j-1,n,m,arr,vis,cnt);
         }
         if(j+1<m && !vis[i][j+1] && arr[i][j+1]!=0)
         {
              cnt+=1;
              dfs(i,j+1,n,m,arr,vis,cnt);
         }
         if(i-1>=0 && !vis[i-1][j] && arr[i-1][j]!=0)
         {
              cnt+=1;
              dfs(i-1,j,n,m,arr,vis,cnt);
         }
         if(i+1<n&& !vis[i+1][j] && arr[i+1][j]!=0)
         {
              cnt+=1;
              dfs(i+1,j,n,m,arr,vis,cnt);
         }
         if(i-1>=0 && j+1<m && !vis[i-1][j+1]&& arr[i-1][j+1]!=0)
         {
              cnt+=1;
              dfs(i-1,j+1,n,m,arr,vis,cnt);
         }
         if(i-1>=0 && j-1>=0 && !vis[i-1][j-1]&& arr[i-1][j-1]!=0)
         {
              cnt+=1;
              dfs(i-1,j-1,n,m,arr,vis,cnt);
         }  
         if(i+1<n && j+1<m && !vis[i+1][j+1]&& arr[i+1][j+1]!=0)
         {
              cnt+=1;
              dfs(i+1,j+1,n,m,arr,vis,cnt);
         }
         if(i+1<n && j-1>=0 && !vis[i+1][j-1] && arr[i+1][j-1]!=0)
         {
             cnt+=1;
             dfs(i+1,j-1,n,m,arr,vis,cnt);
         }
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int count=INT_MIN;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    int c=1;
                    dfs(i,j,n,m,grid,vis,c);
                    count=max(c,count);
                }
            }
        }
        return count;
    }
};
