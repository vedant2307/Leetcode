class Solution {
public:
    string frequencySort(string s) {
        string ans;
        int n=size(s);
        vector<vector<int>>bucket(n+1);
        unordered_map<int,int>mp;
        for(auto it:s) mp[it-'a']++;
        for(auto it:mp){
            int freq=it.second, ch=it.first;
            bucket[freq].push_back(ch);
        }
        for(int idx=n;idx>=1;idx--){
            for(auto it:bucket[idx]){
                int cnt=idx;
                while(cnt--) ans.push_back(it+'a');
            }
        }
        return ans;
    }
};