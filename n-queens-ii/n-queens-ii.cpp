class Solution {
public:
    int ans=0;
    bool isValid(int row,int col,vector<string>&board,int n)
    {
        for(int i=0;i<=col;i++)
        {
            if(board[row][i]=='Q')
                return false;
        }
        int a=row,b=col;
        while(a>=0 && b>=0)
        {
            if(board[a][b]=='Q')
                return false;
            a--;
            b--;
        }

        a=row,b=col;
        while(a<n && b>=0)
        {
            if(board[a][b]=='Q')
                return false;
            a++;
            b--;
        }

        return true;
    }

    void solve(vector<string>&board,int n,int col)
    {
        if(col==n)
        {
            ans++;
            return ;
        }
        for(int row=0;row<n;row++)
        {
            if(isValid(row,col,board,n))
            {
                board[row][col]='Q';
                solve(board,n,col+1);
                board[row][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string>temp(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            temp[i]=s;
        solve(temp,n,0);
        return ans;
    }
};