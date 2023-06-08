class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        int n=s.length();
        int cnt=words.size(),len=words[0].size();
        int tot=cnt*len;
        if(n<tot) return ans;
        unordered_map<string,int>mp;
        for(auto it:words) mp[it]++;
        for(int i=0;i<=n-tot;i++){
            unordered_map<string,int>temp=mp;
            int j;
            for(j=i;j<i+tot;j+=len){
                string st=s.substr(j,len);
                if(temp[st]==0) break;
                else temp[st]--;
            }
            if(j==i+tot) ans.push_back(i);
        }
        return ans;
    }
};