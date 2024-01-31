class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool>vis(n);
        vis[start]=true;
        queue<int>q;
        q.push(start);

        while(!q.empty()){
            int front=q.front(); q.pop();
            if(arr[front]==0) return true;
            int left=front-arr[front],right=front+arr[front];
            if(left>=0 && !vis[left]){
                vis[left]=true;
                q.push(left);
            }
            if(right<n && !vis[right]){
                vis[right]=true;
                q.push(right);
            }
        }

        return false;
    }
};