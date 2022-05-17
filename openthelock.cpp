class Solution {
public:
    string moveUp(string s, int i)
    {
        if(s[i]=='9')
        {
            s[i]='0';
        }
        else
        {
            s[i]++;
        }
        return s;
    }
    string moveDown(string s, int i)
    {
        if(s[i]=='0')
        {
            s[i]='9';
        }
        else
        {
            s[i]--;
        }
        return s;
    }
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        unordered_set<string>vis;
        unordered_set<string>s(deadends.begin(),deadends.end());
        int ans=0;
        q.push("0000");
        vis.insert("0000");
        while(!q.empty())
        {
            int n= q.size();
            while(n--)
            {
                string cur = q.front();
                q.pop();
                if(s.find(cur) != s.end())
                    continue;
                if(cur==target)
                {
                    return ans;
                }
                for(int j = 0; j < 4; j++)
                {
                    string up=moveUp(cur, j);
                    if(vis.find(up)==vis.end())
                    {
                        q.push(up);
                        vis.insert(up);
                    }
                    string down=moveDown(cur, j);
                    if(vis.find(down)==vis.end())
                    {
                        q.push(down);
                        vis.insert(down);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
