class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for(auto it:num){
            while(k>0 && !st.empty() && st.back()>it) {
                st.pop_back(); k--;
            }
            if(st.size() || it!='0') st.push_back(it);
        }
        while(k>0 && st.size()){
            st.pop_back(); k--;
        } 
        return st=="" ? "0" : st;
    }
};