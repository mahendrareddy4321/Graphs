class Solution {
public:
    int f(int i,int j,int n,int m,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        
        if(i<0 || j<0 || i>=n ||j>=m) 
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int d=0,u=0,r=0,l=0;
        if(i+1<n && matrix[i+1][j]>matrix[i][j])
        {
            d =1+f(i+1,j,n,m,matrix,dp);
        }
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j])
        {
            u =1+f(i-1,j,n,m,matrix,dp);
        }
        if(j+1<m && matrix[i][j+1]>matrix[i][j])
        {
            r =1+f(i,j+1,n,m,matrix,dp);
        }
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j])
        {
            l =1+f(i,j-1,n,m,matrix,dp);
        }
        return dp[i][j]=max(d,max(u,max(r,l)));        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int ans= 1;
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
        }
        for(int i = 0; i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,1+f(i, j, n, m,matrix,dp));
            }
        }
        return ans;
    }
};
