class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map<char,int>mp;
        for(auto it:s) mp[it]++;
        int n=s.length();
        priority_queue<pair<int,char>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        while(!pq.empty()){
            auto it=pq.top(); pq.pop();
            int freq=it.first; char ch=it.second;
            while(freq--) ans+=ch;
        }
        return ans;
    }
};