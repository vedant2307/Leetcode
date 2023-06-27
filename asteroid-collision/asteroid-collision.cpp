class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto it:asteroids){
            if(it>0 || st.empty()) st.push(it);
            else{
                while(!st.empty() && st.top()>0 && abs(it)>st.top()) st.pop();
                if(!st.empty() && abs(it)==st.top()) st.pop();
                else if(st.empty() || st.top()<0) st.push(it);
            }
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