class Solution {
public:
    bool check(int row, int col, vector<vector<int>>& cells,int mid,vector<vector<int>>mat)
    {
        int Row[]={0,0,-1,1};
        int Col[]={-1,1,0,0};
        for(int i=0;i<mid;i++)
        {
            int x=cells[i][0],y=cells[i][1];
            mat[x-1][y-1]=1;
        }
        queue<pair<int,int>>q;
        for(int i=0;i<col;i++)
        {
            if(mat[0][i]==0)
            { 
                q.push({0,i}); mat[0][i]=1;
            }
        }
        while(!q.empty())
        {
            int x=q.front().first,y=q.front().second;
            if(x==row-1) return true;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int r=x+Row[i],c=y+Col[i];
                if(r>=0 && c>=0 && r<row && c<col && mat[r][c]==0)
                {
                    q.push({r,c}); mat[r][c]=1;
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) 
    {
        vector<vector<int>>mat(row,vector<int>(col,0));
        int ans,low=1,high=row*col;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(check(row,col,cells,mid,mat))
            {
                ans=mid; low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};