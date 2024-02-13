class Solution {
public:
    string reverseWords(string s) {
        int i=size(s)-1;
        string ans;
        while(i>=0){
            while(i>=0 && s[i]==' ') i--;
            if(i>=0 && s[i]!=' '){
                string temp; 
                while(i>=0 && s[i]!=' ') temp = s[i--]+temp;
                ans = ans+temp+" ";
            }
        }
        ans.pop_back();
        return ans;
    }
};