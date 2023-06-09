class Solution {
public:
    #define pp pair<int,int>
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        int N=arr.size();
        for(int i=0;i<N;i++) pq.push({arr[i],i});
        vector<int>ans(N);
        int t=0,prev=INT_MIN;
        while(!pq.empty()){
            int val=pq.top().first,idx=pq.top().second; 
            pq.pop();
            if(val>prev){
                t++; prev=val;
            }
            ans[idx]=t;
        }
        return ans;
    }
};