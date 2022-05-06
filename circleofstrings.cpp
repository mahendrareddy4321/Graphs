class Solution
{
    public:
    void dfs(int node,vector<vector<int>>&adj,vector<int>&vis)
    {
        vis[node]=1;
        for(int i=0;i<26;i++)
        {
            if(adj[node][i] && !vis[i])
            {
                dfs(i,adj,vis);
            }
        }
    }
    int isCircle(int N, vector<string> A)
    {
        // code here
        vector<int>id(26,0);
        vector<int>od(26,0);
        vector<vector<int>>adj(26,vector<int>(26,0));
        for(int i=0;i<N;i++)
        {
            int u=A[i][0]-'a';
            int v=A[i].back()-'a';
            id[u]++;
            od[v]++;
            adj[u][v]=1;
        }
        vector<int>vis(26,0);
        for(int i=0;i<26;i++)
        {
            if(id[i]!=od[i])
            {
                return 0;
            }
        }
        int it;
        for(int i=0;i<26;i++)
        {
            if(id[i]!=0)
            {
                it=i;
                break;
            }
        }
        dfs(it,adj,vis);
        for(int i=0;i<26;i++)
        {
            if(id[i]!=0 && vis[i]==0)
            {
                return 0;
            }
        }
        return 1;
    }
};
