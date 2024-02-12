class Solution {
public:
    bool checkValidString(string s) {
        stack<int>open,aes;
        int n=size(s);
        for(int i=0;i<n;i++){
            if(s[i]=='(') open.push(i);
            else if(s[i]=='*') aes.push(i);
            else{
                if(!open.empty()) open.pop();
                else if(!aes.empty()) aes.pop();
                else return false;
            }
        }
        while(!open.empty() && !aes.empty()){
            if(open.top()>aes.top()) return false;
            open.pop(); aes.pop();
        }
        return open.empty();
    }
};