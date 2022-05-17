class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        unordered_set<string>vis;
        vector<vector<string>>res;
        queue<vector<string>>q;
        int k=beginWord.size();
        q.push({beginWord});
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                vector<string> currPath = q.front();
                q.pop();
                for(int i=0;i<k;i++)
                {
                    string temp=currPath.back();
                    for(char ch='a';ch<='z';ch++)
                    {
                        temp[i]=ch;
                        if(s.find(temp)!=s.end())
                        {
                            vector<string> newPath=currPath;
                            newPath.push_back(temp);
                            vis.insert(temp);
                            if(temp==endWord)
                            {
                                res.push_back(newPath);
                            }
                            else
                            {
                                q.push(newPath);
                            }
                        }
                    }
                }
            }
            for(auto it: vis)
            {
                s.erase(it);
            }
        }
        return res;
    }
};
