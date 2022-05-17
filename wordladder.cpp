class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s;
        int f=0;
        for(auto it: wordList) 
        {
            s.insert(it);
            if(it==endWord)
            {
                f=1;
            }
        }
        if(f==0)
        {
            return 0;
        }
        queue<string> q;
        q.push(beginWord);
        int ans= 0;
        while(!q.empty()) {
            ans++;
            int n= q.size();
            while(n--) {
                string curr = q.front();
                q.pop();
                for(int i = 0;i<curr.length();i++) 
                {
                    string tmp=curr;
                    for(char ch ='a';ch<='z';ch++) 
                    {
                        tmp[i] = ch;
                        if(tmp == endWord) 
                        {
                            return ans+1;
                        }
                        if(s.count(tmp) ) 
                        {
                            q.push(tmp);
                            s.erase(tmp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
