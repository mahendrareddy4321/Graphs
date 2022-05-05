class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int x1= KnightPos[0];
	    int x2= TargetPos[0];
	    int y1= KnightPos[1];
	    int y2= TargetPos[1];
	    if(x1==x2 && y1==y2)
	    {
	        return 0;
	    }
	    vector<vector<int>>vis(N,vector<int>(N,0));
	    queue<pair<int,int>>q;
	    q.push({x1-1,y1-1});
	    vis[x1-1][y1-1]=0;
	    int c=0;
	    while(!q.empty())
	    {
	        auto it=q.front();
	        q.pop();
	        int i=it.first,j=it.second;
	        if(i-2>=0 && j-1>=0 && i-2<N && j-1<N && vis[i-2][j-1]==0)
	        {
	            vis[i-2][j-1]= 1+vis[i][j];
	            q.push({i-2,j-1});
	        }
	        if(i-2>=0 && j+1>=0 && i-2<N && j+1<N && vis[i-2][j+1]==0){
	            vis[i-2][j+1]= 1+vis[i][j];
	            q.push({i-2,j+1});
	        }
	        if(i-1>=0 && j+2>=0 && i-1<N && j+2<N && vis[i-1][j+2]==0){
	            vis[i-1][j+2]= 1+vis[i][j];
	            q.push({i-1,j+2});
	        }
	        if(i+1>=0 && j+2>=0 && i+1<N && j+2<N && vis[i+1][j+2]==0){
	            vis[i+1][j+2]= 1+vis[i][j];
	            q.push({i+1,j+2});
	        }
	        
	        if(i+2>=0 && j-1>=0 && i+2<N && j-1<N && vis[i+2][j-1]==0){
	            vis[i+2][j-1]= 1+vis[i][j];
	            q.push({i+2,j-1});
	        }
	        if(i+2>=0 && j+1>=0 && i+2<N && j+1<N && vis[i+2][j+1]==0){
	            vis[i+2][j+1]= 1+vis[i][j];
	            q.push({i+2,j+1});
	        }
	        if(i-1>=0 && j-2>=0 && i-1<N && j-2<N && vis[i-1][j-2]==0){
	            vis[i-1][j-2]= 1+vis[i][j];
	            q.push({i-1,j-2});
	        }
	        if(i+1>=0 && j-2>=0 && i+1<N && j-2<N && vis[i+1][j-2]==0){
	            vis[i+1][j-2]= 1+vis[i][j];
	            q.push({i+1,j-2});
	        }
	    }
	    return vis[x2-1][y2-1];
	}
};
