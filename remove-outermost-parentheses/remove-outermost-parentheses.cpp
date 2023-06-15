class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans; int open=0;
        for(auto it:s){
            if(it=='('){
                if(open>0) ans.push_back(it); 
                open++;
            }
            else{
                if(open>1) ans.push_back(it);
                open--;
            }
        }
        return ans;
    }
};