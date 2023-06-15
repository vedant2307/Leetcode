class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int,int>mp;
        for(auto it:s) mp[it]++;
        int n=s.length();
        vector<vector<int>>temp(n+1);
        for(auto it:mp){
            temp[it.second].push_back(it.first-'0');
        }
        string ans;
        for(int i=n;i>=1;i--){
            if(temp[i].size()>0){
                for(auto it:temp[i]){
                    string temp(i,it+'0');
                    ans+=temp;
                }
            }
        }
        return ans;
    }
};