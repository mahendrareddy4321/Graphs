class Solution {
public:
    vector<int>dx={0,-1,0,1,1,1,-1,-1};
    vector<int>dy={-1,0,1,0,1,-1,1,-1};
    bool possible(int i,int j,string &s,vector<vector<char>>& board,int k)
    {
        if(k==s.size())
        {
            return true;
        }
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=s[k])
        {
            return false;
        }
        char ch=board[i][j];
        board[i][j]='.';
        for(int in=0;in<8;in++)
        {
            if(possible(i+dx[in],j+dy[in],s,board,k+1))
            {
                board[i][j]=ch;
                return true;
            }
        }
        board[i][j]=ch;
        return false;
    }
    bool isexist(string &s,vector<vector<char>>& board)
    {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(possible(i,j,s,board,0))
                {
                    return true;
                }
            }
        }
        return false;
    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	    vector<string>v;
	    for(auto i:dictionary)
	    {
	        if(isexist(i,board))
	        {
	            v.push_back(i);
	        }
	    }
	    return v;
	}
};
