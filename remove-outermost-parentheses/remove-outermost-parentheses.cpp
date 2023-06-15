class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int i=0,j=0,n=s.size();
        while(j<n){
            i=j;
            if(s[j]=='('){
                int open=0,close=0;
                while(j<n){
                    if(s[j]=='(') open++;
                    else close++;
                    if(open==close) break;
                    j++;
                }
                for(int idx=i+1;idx<j;idx++) ans.push_back(s[idx]);
            }
            j++;
        }
        return ans;
    }
};