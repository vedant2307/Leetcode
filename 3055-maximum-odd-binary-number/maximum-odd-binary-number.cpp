class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt=0;
        for(auto it:s) if(it=='1') cnt++;
        int n=s.length();
        s[n-1]='1'; cnt--;
        for(int i=0;i<n-1;i++){
            if(cnt>0){
                s[i]='1'; cnt--;
            }
            else s[i]='0';
        }  
        return s;
    }
};