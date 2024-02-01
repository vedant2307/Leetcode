class Solution {
public:
    #define ll long long
    ll helper(vector<int>& arr,bool flg) {
        stack<int>st;
        st.push(-1);
        ll ans=0;
        int n=arr.size();
        for(int idx=0;idx<n;idx++){
            while(st.size()>1 && (flg ? arr[st.top()]>=arr[idx] : arr[st.top()]<=arr[idx])){
                int top=st.top(); st.pop();
                ll left=top-st.top(),right=idx-top;
                ll temp = arr[top]*left*right;
                ans = ans+temp;
            }
            st.push(idx);
        }
        while(st.size()>1){
            int top=st.top(); st.pop();
            ll left=top-st.top(),right=n-top;
            ll temp = arr[top]*left*right;
            ans = ans+temp;
        }
        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        ll t1=helper(nums,true);
        ll t2=helper(nums,false);
        return t2-t1;
    }
};