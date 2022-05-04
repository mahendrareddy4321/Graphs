class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        unordered_map<int,int>snk;
        unordered_map<int,int>lad;
        for(int i=0;(i+1)<N*2;i+=2)
        {
            if(arr[i]<arr[i+1])
                snk[arr[i]]=arr[i+1];
            else
                lad[arr[i]]=arr[i+1];
        }
        int moves=0;
        queue<int>q;
        q.push(1);
        vector<int>vis(31,0);
        vis[1]=1;
        bool flag=false;
        while(!q.empty() && flag==false)
        {
            int n=q.size();
            while(n--)
            {
                int t=q.front();
                q.pop();
                for(int i=1;i<=6;i++)
                {
                    if(t+i==30)
                    {
                        flag=true;
                    }
                    else if(t+i<=30 and lad[t+i] and !vis[lad[t+i]])
                    {
                        vis[lad[t+i]]=1;
                        if(lad[t+i]==30)
                        {
                            flag=true;
                        }
                        q.push(lad[t+i]);
                    }
                    else if(t+i<=30 and snk[t+i] and !vis[snk[t+i]])
                    {
                        vis[snk[t+i]]=1;
                        if(snk[t+i]==30)
                        {
                            flag=true;
                        }
                        q.push(snk[t+i]);
                    }
                    else if(t+i<=30 and !vis[t+i])
                    {
                        vis[t+i]=1;
                        q.push(t+i);
                    }
                }
            }
            moves++;
        }
        if(flag==false)
        {
            return -1;
        }
        return moves;
    }
};
