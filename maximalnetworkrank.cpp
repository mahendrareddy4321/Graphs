class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        vector<vector<int>>adj(n,vector<int>(n, 0));
        for (auto it: roads) 
        {
          degree[it[0]]++;
          degree[it[1]]++;
          adj[it[1]][it[0]]=1;
          adj[it[0]][it[1]]=1;
        }

        int res =INT_MIN;
        for(int i=0;i<n;i++)
        {
           for(int j=i+1;j<n;j++) 
           {
              res=max(res,degree[i]+degree[j]-adj[i][j]);
           }
        }
        return res;
    }
};
