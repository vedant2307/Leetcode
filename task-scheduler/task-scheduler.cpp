class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sz=tasks.size();
        unordered_map<char,int>mp;
        for(auto it:tasks) mp[it]++;
        priority_queue<int>pq;
        for(auto it:mp) pq.push(it.second);
        int maxi=pq.top()-1; pq.pop();
        int idleSpots=maxi*n;
        while(!pq.empty()){
            idleSpots-=min(maxi,pq.top()); pq.pop();
        }
        return max(sz,sz+idleSpots);
    }
};