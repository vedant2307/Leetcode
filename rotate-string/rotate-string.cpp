class Solution {
public:
    bool rotateString(string s, string goal) {
        int len=s.length(),n=goal.length();
        if(len!=n) return false;
        s=s+s;
        for(int i=0;i<n;i++){
            string temp=s.substr(i,len);
            if(temp==goal) return true;
        }
        return false;
    }
};