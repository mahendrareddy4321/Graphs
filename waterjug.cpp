class Solution {
public:
    bool canMeasureWater(int j1, int j2, int t) {
        unordered_set<int>s;
        queue<int>q;
        q.push(0);
        while(!q.empty())
        {
            int n=q.front();
            q.pop();
            if(n>=0 && n<=j1+j2)
            {
                vector<int>v={j1,j2,-j1,-j2};
                for(int i=0;i<4;i++)
                {
                    if(n+v[i]==t)
                    {
                        return true;
                    }
                    else
                    {
                        if(s.find(n+v[i])==s.end())
                        {
                            s.insert(n+v[i]);
                            q.push(n+v[i]);
                        }
                    }
                }
            }
        }
        return false;
    }
};
