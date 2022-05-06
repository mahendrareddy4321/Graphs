class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> ar, int X, int Y) {
        // code here
        vector<vector<int>>vis(N+1,vector<int>(M+1,0));
        if(ar[0][0]==0 || ar[X][Y]==0)
        {
            return -1;
        }
        int ans=0;
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=1;
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                auto node=q.front();
                q.pop();
                int i=node.first;
                int j=node.second;
                if(i==X && j==Y)
                {
                    return ans;
                }
                if(i-1>=0 && ar[i-1][j]!=0 && !vis[i-1][j])
                {
                    vis[i-1][j]=1;
                    q.push({i-1,j});
                }
                if(j-1>=0 && ar[i][j-1]!=0 && !vis[i][j-1])
                {
                    vis[i][j-1]=1;
                    q.push({i,j-1});
                }
                if(i+1<ar.size() && ar[i+1][j]!=0 && !vis[i+1][j])
                {
                    vis[i+1][j]=1;
                    q.push({i+1,j});
                }
                if(j+1<ar[0].size() && ar[i][j+1]!=0 && !vis[i][j+1])
                {
                    vis[i][j+1]=1;
                    q.push({i,j+1});
                }
            }
            ans++;
        }
        return -1;
    }
};
