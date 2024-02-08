class Solution {
public:
    int numSquares(int n) {
        queue<int>q;
        q.push(n);
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int num=q.front(); q.pop();
                if(num==0) return ans;
                for(int idx=sqrt(num);idx>=1;idx--){
                    int t=idx*idx;
                    if(t<=num) q.push(num-t);
                }
            }
            ans++;
        }
        return -1;
    }
};