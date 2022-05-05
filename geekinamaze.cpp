class Solution{
 
	public:
	int numberOfCells(int n, int m, int r, int c, int u, int d, vector<vector<char>> &mat)
	{
		// Your code goes here
		queue<vector<int>>q;
		q.push({r,c,0,0});
		if(mat[r][c]=='#')
		{
		    return 0;
		}
		mat[r][c]=1;
		int ans=1;
		while(!q.empty())
		{
		    int x=q.front()[0];
		    int y=q.front()[1];
		    int t=q.front()[2];
		    int b=q.front()[3];
		    q.pop();
		    if(y-1>=0 && mat[x][y-1]=='.')
		    {
		        q.push({x,y-1,t,b});
		        mat[x][y-1]=1;
		        ans++;
		    }
		    if(y+1<m && mat[x][y+1]=='.')
		    {
		        q.push({x,y+1,t,b});
		        mat[x][y+1]=1;
		        ans++;
		    }
		    if(x-1>=0 && t!=u && mat[x-1][y]=='.')
		    {
		        q.push({x-1,y,t+1,b});
		        mat[x-1][y]=1;
		        ans++;
		    }
		    if(x+1<n && b!=d && mat[x+1][y]=='.')
		    {
		        q.push({x+1,y,t,b+1});
		        mat[x+1][y]=1;
		        ans++;
		    }
		}
		return ans;
	}

};
