class Solution {
public:
    vector<int> calc(int row,int next_step)
    {
        int x=(next_step-1)/row;
        int y=(next_step-1)%row;
        if(x%2==1)
        {
            y=row-1-y;
        }
        x=row-1-x;
        return {x,y};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int N=board.size();
        int tot=N*N;
        int moves=0;
        queue<int>q;
        q.push(1);
        vector<int>vis(tot+1,0);
        vis[1]=1;
        bool flag=false;
        while(!q.empty() && flag==false)
        {
            int n=q.size();
            while(n--)
            {
                int t=q.front();
                q.pop();
                if(t==tot)
                {
                    return moves;
                }
                for(int i=1;i<=6;i++)
                {
                    int next_step=t+i;
                    if(next_step>tot)break;
                    auto v=calc(N,next_step);
                    int row=v[0],col=v[1];
                    if(board[row][col]!=-1)
                    {
                        next_step=board[row][col];
                    }
                    if(board[row][col]!=tot+1)
                    {
                        q.push(next_step);
                        board[row][col]=tot+1;
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};
