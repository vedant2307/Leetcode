class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto ch:tokens){
            if(ch=="+"){
                int val1=st.top(); st.pop();
                int val2=st.top(); st.pop();
                st.push(val1+val2);
            }
            else if(ch=="-"){
                int val1=st.top(); st.pop();
                int val2=st.top(); st.pop();
                st.push(val2-val1);
            }
            else if(ch=="*"){
                int val1=st.top(); st.pop();
                int val2=st.top(); st.pop();
                st.push(val1*val2);
            }
            else if(ch=="/"){
                int val1=st.top(); st.pop();
                int val2=st.top(); st.pop();
                st.push(val2/val1);
            }
            else{
                int num=stoi(ch);
                st.push(num);
            }
        }
        return st.top();
    }
};