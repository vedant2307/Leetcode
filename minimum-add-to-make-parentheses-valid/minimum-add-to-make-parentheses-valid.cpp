class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0;
        stack<int>st;
        for(auto it:s){
            if(it==')'){
                if(st.empty()) cnt++;
                else st.pop();
            }
            else st.push(it);
        }
        return cnt+st.size();
    }
};