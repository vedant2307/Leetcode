class Solution {
public:
    int findTargetSumWays(vector<int>&arr, int d) {
        int n=arr.size();
	    int sum=accumulate(arr.begin(),arr.end(),0);
        int tot=(sum+abs(d));
        if(tot%2 || abs(d)>sum) return 0;
        tot=tot/2;
        vector<int>prev(sum+1);
        prev[0]=1;
        for(int idx=n-1;idx>=0;idx--){
            vector<int>curr(sum+1);
            for(int s=0;s<=sum;s++){
                int a=false;
                if(arr[idx]<=s) a=prev[s-arr[idx]];
                int b=prev[s];
                curr[s] = (a + b);
            }
            prev=curr;
        }
        return prev[tot];
    }
};