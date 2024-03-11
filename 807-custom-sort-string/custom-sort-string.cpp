class Solution {
public:
    string customSortString(string order, string s) {
        string ans;
        unordered_map<char,int>mp;
        for(int i=0;i<order.size();i++) mp[order[i]]=i; 
        map<int,int>mp1;
        for(auto it:s){
            if(mp.find(it)!=mp.end()) mp1[mp[it]]++;
            else ans+=it;
        }
        for(auto it:mp1){
            char ch=order[it.first]; 
            string temp(it.second,ch); 
            ans+=temp;
        }
        return ans;
    }
};