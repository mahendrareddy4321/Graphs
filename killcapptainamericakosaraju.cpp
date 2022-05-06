class Solution{
public:
    void dfs(int node,vector<int> adj[],vector<int>&vis)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis);
            }
        }
    }
    int captainAmerica(int N, int M, vector<vector<int>> &V){
        // Code Here
        vector<int>adj[N+1],vis(N+1);
        for(int i=0;i<M;i++)
        {
            adj[V[i][1]].push_back(V[i][0]);
        }
        int parent=-1;
        for(int i=1;i<=N;i++)
        {
            if(!vis[i])
            {
                parent=i;
                dfs(i,adj,vis);
            }
        }
        fill(vis.begin(),vis.end(),0);
        dfs(parent,adj,vis);
        for(int i=1;i<=N;i++)
        {
            if(!vis[i])
            {
                return 0;
            }
        }
        vector<int>trans[N+1];
        for(int i=0;i<M;i++)
        {
            trans[V[i][0]].push_back(V[i][1]);
        }
        queue<int>q;
        q.push(parent);
        fill(vis.begin(),vis.end(),0);
        vis[parent]=1;
        int res=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:trans[node])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
            res++;
        }
        return res;
    } 
};
