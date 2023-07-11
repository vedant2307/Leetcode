class Solution {
    vector<vector<string>>ans;
    bool check(int row,int col,int n,vector<string>&str){
        int rowC=row,colC=col;
        while(col--) if(str[row][col]=='Q') return false;
        row=rowC; col=colC;
        while(row>=0 && col>=0){
            if(str[row][col]=='Q') return false;
            row--; col--;
        }
        row=rowC; col=colC;
        while(row<n && col>=0){
            if(str[row][col]=='Q') return false;
            row++; col--;
        }
        return true;
    }
public:
    void solve(vector<string>&str,int col,int n){
        if(col==n) { ans.push_back(str); return; }
        for(int row=0;row<n;row++){
            if(check(row,col,n,str)){
                str[row][col]='Q';
                solve(str,col+1,n);
                str[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string t(n,'.');
        vector<string>str(n,t);
        //for(int i=0;i<n;i++) str[i]=t;
        solve(str,0,n);
        return ans;
    }
};