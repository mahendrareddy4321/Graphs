class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(int node,vector<int> adj[],int c,int d,vector<int>&vis)
    {
        vis[node] = 1; 
        for(auto it: adj[node]) {
            if(!vis[it] && (node!=c || it!=d)) {
                dfs(it,adj,c,d,vis);
            }
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
    	vector<int> vis(V ,0);
    	dfs(c,adj,c,d,vis);
    	return !vis[d];
    }
};
