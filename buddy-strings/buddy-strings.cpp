class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n=s.length(), m=goal.length();
        if(m!=n) return false;
        int cnt=0; bool flg=false;
        vector<int>freq(26,0),a,b;
        for(int i=0;i<n;i++){
            if(freq[s[i]-'a']++==1) flg=true;
            if(s[i]!=goal[i]){
                a.push_back(s[i]); b.push_back(goal[i]); cnt++;
            }
            if(cnt>2) return false;
        }
        if(cnt==0) return flg;
        if(cnt==2){
            if(a[0]==b[1] && a[1]==b[0]) return true;
        }
        return false;
    }
};