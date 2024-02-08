class Solution {
public:
    int numSquares(int n) {
        queue<pair<int,int>>q;
        q.push({n,0});
        while(!q.empty()){
            auto front=q.front(); q.pop();
            int num=front.first, ans=front.second;
            if(num==0) return ans;
            for(int idx=sqrt(num);idx>=1;idx--){
                int t=idx*idx;
                if(t<=num) q.push({num-t,ans+1});
            }
        }
        return -1;
    }
};