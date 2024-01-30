class Solution {
public:
    int countKeyChanges(string s) {
        int ans=0;
        char ch=s[0];
        if(ch>='A' && ch<='Z') ch=ch+32;
        for(int idx=1;idx<s.length();idx++){
            char x=s[idx];
            if(x>='A' && x<='Z') x=x+32;
            if(ch!=x){
                ans++;
                ch=x;
            }
        }
        return ans;
    }
};