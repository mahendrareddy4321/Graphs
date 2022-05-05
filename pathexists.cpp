class Solution {
public:
    int parent[1000000];
    void makeset(int n)
    {
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    int findpar(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=findpar(parent[node]);
    }
    void unionn(int u,int v)
    {
        u=findpar(u);
        v=findpar(v);
        parent[u]=v;
    } 
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        makeset(n);
        for(auto it:edges)
        {
            unionn(it[0],it[1]);
        }
        return findpar(source)==findpar(destination);
    }
};
