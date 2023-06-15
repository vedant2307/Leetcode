class Solution {
public:
    bool helper(string a,string b,int rot,int n){
        for(int j=0;j<n;j++){
            if(a[j]!=b[(rot+j)%n]) return false;
        }
        return true;
    }
    bool rotateString(string s, string goal) {
        int len=s.length(),n=goal.length();
        if(len!=n) return false;
        for(int i=0;i<n;i++){
            if(helper(s,goal,i,n)) return true;
        }
        return false;
    }
};