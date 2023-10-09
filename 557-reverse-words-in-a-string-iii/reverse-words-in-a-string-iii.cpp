class Solution {
public:
    void reverse(string &s,int i,int j){
        while(i<j){
            swap(s[i],s[j]);
            i++; j--;
        }
        return ;
    }
    string reverseWords(string s) {
        int n=s.length();
        if(n<=1) return s;
        int i=0,j=0;
        while(j<n){
            while(j<n && s[j]!=' '){
                j++;
            }
            reverse(s,i,j-1);
            j++;
            i=j;
        }
        return s;
    }
};