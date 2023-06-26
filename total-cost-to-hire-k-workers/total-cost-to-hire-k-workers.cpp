class Solution {
    #define ll long long
public:
    long long totalCost(vector<int>& cost, int k, int c) {
        ll ans=0LL; int n=cost.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int i=0,j=n-1,cnt=0;
        while(cnt<c){
            pq.push({cost[i],0}); i++; cnt++;
        }
        cnt=0;
        while(j>=i && cnt<c){
            pq.push({cost[j],1}); j--; cnt++;
        }
        while(k--){
            auto it=pq.top(); pq.pop();
            int top=it.first,flg=it.second;
            ans+=top;
            if(flg){
                if(j>=i){
                    pq.push({cost[j],1}); j--;
                }
            }
            else{
                if(i<=j){
                    pq.push({cost[i],0}); i++;
                }
            }
        }
        return ans;
    }
};