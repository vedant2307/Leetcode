class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto it:asteroids){
            bool flg=true;
            if(!st.empty() && st.top()>0){
                if(it<0){
                    flg=false;
                    while(!st.empty() && st.top()>0 && abs(it)>st.top()){
                        st.pop();
                    } 
                    if(!st.empty() && abs(it)==st.top()) st.pop();
                    else if(st.empty() || st.top()<0) st.push(it);
                }
            }
            if(flg) st.push(it);
        }
        int n=st.size();
        vector<int>ans(n);
        int idx=n-1;
        while(!st.empty()){
            ans[idx--]=st.top(); st.pop();
        }
        return ans;
    }
};