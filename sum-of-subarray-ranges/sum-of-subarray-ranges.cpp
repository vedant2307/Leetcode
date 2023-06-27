class Solution {
public:
    long long helper(vector<int>& arr,bool flg) {
        int n=arr.size(); vector<int>prev(n),next(n); stack<int>st; 
        for(int idx=0;idx<n;idx++){
            while(!st.empty() && (flg ? arr[st.top()]>arr[idx] : arr[st.top()]<=arr[idx])) st.pop();
            if(st.empty()) prev[idx]=idx+1;
            else prev[idx]=idx-st.top();
            st.push(idx);
        }
        while(!st.empty()) st.pop();
        for(int idx=n-1;idx>=0;idx--){
            while(!st.empty() && (flg ? arr[st.top()]>=arr[idx] : arr[st.top()]<arr[idx])) st.pop();
            if(st.empty()) next[idx]=n-idx;
            else next[idx]=st.top()-idx;
            st.push(idx);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long cnt1=prev[i],cnt2=next[i];
            long long temp=(cnt1*cnt2);
            temp=(temp*arr[i]);
            ans= (ans+temp);
        }
        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long t1=helper(nums,true);
        long long t2=helper(nums,false);
        return t2-t1;
    }
};