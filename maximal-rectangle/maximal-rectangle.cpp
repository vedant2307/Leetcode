class Solution {
public:
    int MaxArea(vector<int>&arr,int n)
    {
        stack<int>st;
        st.push(-1);
        int ans=0;
        for(int idx=0;idx<n;idx++){
            while(st.size()>1 && arr[st.top()]>arr[idx]){
                int top=st.top(); st.pop();
                int left=top-st.top(),right=idx-top;
                int temp = (left+right-1)*arr[top];
                ans = max(ans,temp);
            }
            st.push(idx);
        }
        while(st.size()>1){
            int top=st.top(); st.pop();
            int left=top-st.top(),right=n-top;
            int temp = (left+right-1)*arr[top];
            ans = max(ans,temp);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        vector<int>temp(n,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                    temp[j]++;
                else
                    temp[j]=0;
            }
            int t = MaxArea(temp,n);
            ans=max(ans,t);
        }
        return ans;
    }
};