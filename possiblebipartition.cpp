class Solution {
public:
    bool dfs(int node, vector<int> adj[],vector<int>& color)
    {
        for(auto it: adj[node])
        {
            if(color[it]==-1)
            {   
                color[it]=1-color[node];
                if(!dfs(it, adj, color))
                {
                    return false;
                }
            }
            else if(color[it] == color[node])
            {
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
        for(auto it:dislikes)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> color(n+1, -1);
        for(int i=1; i<=n; i++)
        {
            if(color[i]==-1)
            {   
                color[i] = 0;
                if(!dfs(i,adj,color)) 
                {
                    return false;
                }
            }
        }
        return true;
    }
};
