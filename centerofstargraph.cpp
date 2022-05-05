class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int k,l;
        k=edges[0][0];
        l=edges[0][1];
        for(int i=1;i<edges.size();i++)
        {
            if(k==edges[i][0] || k==edges[i][1])
            {
                return k;
            }
            if(l==edges[i][1] || l==edges[i][1])
            {
                return l;
            }
        }
        return -1;
    }
};
