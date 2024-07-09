class Solution {
public:
    // int solve(int n, int k){
    //     if(n==1) return 0;
    //     return (solve(n-1,k)+k)%n;
    // }
    int findTheWinner(int n, int k) {
        // return solve(n,k)+1;
        queue<int>q;
        for(int i=1;i<=n;i++) q.push(i);
        while(q.size()>1){
            for(int i=1;i<k;i++){
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};