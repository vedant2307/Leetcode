class Solution {
public:
    int len=0; string ans;
    void helper(int l,int r,int n,string str){
        while(l>=0 && r<n){
            if(str[l]!=str[r]) break;
            l--; r++;
        }
        if(r-l-1>len){
            len=r-l-1;
            ans=str.substr(l+1,len);
        }
    }
    string longestPalindrome(string str) {
        int n=str.length();
        for(int i=0;i<n;i++){
            helper(i-1,i+1,n,str);
            helper(i-1,i,n,str);
        }
        return ans;
    }
};