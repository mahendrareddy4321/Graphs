class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int node,vector<int> adj[],vector<int>&vis,int &c)
    {
        vis[node]=1;
        c++;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis);
            }
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
        for(int i=0;i<V;i++)
        {
            int c=0;
            vector<int>vis(V,0);
            dfs(i,adj,vis,c);
            if(c==V)
            {
                return i;
            }
        }
        return -1;
	}

};
