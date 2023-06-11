class Solution {
    #define ll long long
public:
    ll helper(ll tot,ll n){
        ll sum=n*(n+1)/2,rem_sum;
        ll rem;
        if(n>tot){
            rem=n-tot;
            rem_sum=(rem)*(rem+1)/2;
            sum-=rem_sum;
        }
        else{
            rem=tot-n;
            rem_sum=rem;
            sum+=rem_sum;
        }
        return sum;
    }
    int maxValue(int n, int idx, int maxSum) {
        int low=1,high=maxSum-n+1,ans;
        while(low<=high){
            ll mid=low+(high-low)/2;
            ll leftSum=helper((ll)idx,mid-1);
            ll rightSum=helper((ll)n-1-idx,mid-1);
            ll Sum=leftSum+rightSum+mid;
            if(Sum<=maxSum) { ans=mid; low=mid+1; }
            else high=mid-1;
        }
        return ans;
    }
};